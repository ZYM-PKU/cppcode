//
// This is example code from Chapter 7.7 "Recovering from errors" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>


using namespace std;

inline void keep_window_open()
{
    cin.get();
}

inline void error(const string& errormessage)
{
    throw runtime_error(errormessage);
}

//------------------------------------------------------------------------------
/*
Simple calculator

This program implements a basic expression calculator.
Input from cin; output to cout.

The grammar for input is:

Statement:
    Expression
    Print
    Quit

Print:
    ;

Quit:
    q

Expression:
    Term
    Expression + Term
    Expression - Term
Term:
    Primary
    Term * Primary
    Term / Primary
    Term % Primary
Primary:
    Number
    ( Expression )

Number:
    floating-point-literal


Input comes from cin through the Token_stream called ts.
*/
//------------------------------------------------------------------------------

const char number = '8';    // t.kind==number means that t is a number Token
const char quit = 'q';      // t.kind==quit means that t is a quit Token
const char print = ';';     // t.kind==print means that t is a print Token
const string prompt = "> ";
const string result = "= "; // used to indicate that what follows is a result

//------------------------------------------------------------------------------
class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};
//------------------------------------------------------------------------------
class Token_stream {
public:
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
    void ignore(char c);      // discard tokens up to an including a c
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};
//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
    :full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------
// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------
Token Token_stream::get() // read characters from cin and compose a Token
{
    if (full) {         // check if we already have a Token ready
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;          // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case quit:
    case print:
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    case '!':
        return Token(ch); // let each character represent itself
    case '.':             // a floating-point literal can start with a dot
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':    // numeric literal
    {
        cin.putback(ch);// put digit back into the input stream
        double val;
        cin >> val;     // read a floating-point number
        return Token(number, val);
    }
    default:
        error("Bad token");
        return Token('b');
    }
    return {'0', 0.0};
}

//------------------------------------------------------------------------------

void Token_stream::ignore(char c)
// c represents the kind of a Token
{
    // first look in buffer:
    if (full && c == buffer.kind) {
        full = false;
        return;
    }
    full = false;

    // now seach input:
    char ch = 0;
    while (cin >> ch)
        if (ch == c) return;
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback() 

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()
double primary();
double term();
double mini();//优先级最高的运算单元（用于处理阶乘）

//------------------------------------------------------------------------------


double my_calc(double v){//计算阶乘
    int result=1;
    v=(int)v;
    if(v==0)return 1;
    for(int i=1;i<=v;i++)result*=i;
    return (double)result;
}





double mini(){//优先级最高的运算单元（用于处理阶乘）
    double left = primary();
    Token t = ts.get(); // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '!':
            return my_calc(left);
            break;
        default:
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}




// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':           // handle '(' expression ')'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') error("')' expected");
        return d;
    }
    case number:
        return t.value;    // return the number's value
    default:
        error("primary expected");
        return 0;
    }
    return 0.0;
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
    double left = mini();
    Token t = ts.get(); // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '*':
            left *= mini();
            t = ts.get();
            break;
        case '/':
        {
            double d = mini();
            if (d == 0) error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------
// deal with + and -
double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}
//------------------------------------------------------------------------------

void clean_up_mess()
{
    ts.ignore(print);
}

//------------------------------------------------------------------------------
void calculate()
{
    while (cin)
        try {
        Token t = ts.get();
        while (t.kind == print) t = ts.get();    // first discard all "prints"
        if (t.kind == quit) return;            // quit
        ts.putback(t);
        cout << result << expression() << endl;
    }
    catch (runtime_error& e) {
        cerr << e.what() << endl;              // write error message
        clean_up_mess();
    }
}
//------------------------------------------------------------------------------

int main()
try {
    calculate();
    keep_window_open();    // cope with Windows console mode
    return 0;
}
catch (exception& e) {
    cerr << e.what() << endl;
    keep_window_open();
    return 1;
}
catch (...) {
    cerr << "exception \n";
    keep_window_open();
    return 2;
}

//------------------------------------------------------------------------------
