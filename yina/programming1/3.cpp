//改进版简易计算器，支持{}

#include<bits/stdc++.h>


using namespace std;
//------------------------------------------------------------------------------


class Variable {
public:
    string name;
    double value;
    Variable (string n, double v) :name(n), value(v) { }
};//变量

vector<Variable> var_table;


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
    Token_stream():full(false), buffer(0){}   // make a Token_stream that reads from cin The constructor just sets full to indicate that the buffer is empty
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
    ~Token_stream(){}
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};



//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:


//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full)  throw runtime_error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full=false;
        return buffer;
    } 

    char ch;
    ch=getchar();    // note that >> skips whitespace (space, newline, tab, etc.)
    while(ch==' ')ch=getchar();

    switch (ch) {
    case '\n':    // for "print"
    case 'q':    // for "quit"
    case 'l':    //for "let"
    case '(': case ')': case '{':case '}':case '+': case '-': case '*': case '/': 
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        {    
            cin.putback(ch);         // put digit back into the input stream
            double val;
            cin >> val;              // read a floating-point number
            return Token('n',val);   // let 'n' represent "a number"
        }
    default:
        cin.putback(ch);
        char temp;
        cin>>temp;
        for(Variable v :var_table){
            if(v.name[0]==temp){
                for(int i=1;i<v.name.length();i++)getchar();
                return Token('n',v.value);
            }
        }
    }
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback() 

//------------------------------------------------------------------------------





double expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
        {    
            double d = expression();
            t = ts.get();
            if (t.kind != ')')  throw runtime_error("')' expected");
            return d;
        }
    case '{':
        {
            double d = expression();
            t = ts.get();
            if (t.kind != '}')  throw runtime_error("'}' expected");
            return d;
        }
    case 'n':            // we use 'n' to represent a number
        return t.value;  // return the number's value
    default:
         throw runtime_error("primary expected");
    }
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
    double left = primary();
    Token t = ts.get();        // get the next token from token stream

    while(true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
            {    
                double d = primary();
                if (d == 0)  throw runtime_error("divide by zero");
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

    while(true) {    
        switch(t.kind) {
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



int main()
try
{
    bool judge=true;
    Variable v1("pi",3.1415926535),v2("e",2.7182818284);
    var_table.push_back(v1);
    var_table.push_back(v2);
    double val = 0;
    while (cin) {
        Token t = ts.get();
        if(judge==false){
            judge=true;
            continue;
        }
        if (t.kind == 'q') break; // 'q' for quit
        if (t.kind == '\n')        // ';' for "print now"
            cout<<fixed<<setprecision(6)<<val<<endl;
        else if(t.kind=='l'){
            getchar();
            getchar();
            char str[100]={0};
            for(int i=0;;i++){
                char temp;
                cin>>temp;
                if(temp=='='){
                    cin.putback(temp);
                    break;
                }
                str[i]=temp;
            }
            string name;
            name=(string)str;
            char ch;
            ch=getchar();
            while(ch!='=')ch=getchar();
            double value=expression();
            Variable var(name,value);
            var_table.push_back(var);
            judge=false;
        }
        else{
            ts.putback(t);
            val = expression();
        }
    }
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
    return 2;
}
