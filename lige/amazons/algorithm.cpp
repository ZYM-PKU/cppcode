#include<iostream>
#include<string>
#include<cstdlib>
#include<cmath>
#include<time.h>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<stack>
#include<queue>
#include<stdlib.h>
#include<ctime>

#define GRIDSIZE 8
#define OBSTACLE 2
#define judge_black 0
#define judge_white 1
#define grid_black 1
#define grid_white -1
#define infinity 0xfffff

using namespace std;

int currBotColor; // 我所执子颜色（1为黑，-1为白，棋盘状态亦同）
int gridInfo[GRIDSIZE][GRIDSIZE] = { 0 }; // 先x后y，记录棋盘状态
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };

int turnID;
int choice=0;
int bestgo=0;
int DEPTH=0;
clock_t start,finish;
double value=0;
bool judgeend=false;//判断何时跳出





// 判断是否在地图内
inline bool inMap(int x, int y){
	if (x < 0 || x >= GRIDSIZE || y < 0 || y >= GRIDSIZE)
		return false;
	return true;
}


////////////////在坐标处落子，检查是否合法或模拟落子//////////////
bool ProcStep(int x0, int y0, int x1, int y1, int x2, int y2, int color, bool check_only){
	if ((!inMap(x0, y0)) || (!inMap(x1, y1)) || (!inMap(x2, y2)))
		return false;
	if (gridInfo[x0][y0] != color || gridInfo[x1][y1] != 0)
		return false;
	if ((gridInfo[x2][y2] != 0) && !(x2 == x0 && y2 == y0))
		return false;
	if (!check_only)
	{
		gridInfo[x0][y0] = 0;
		gridInfo[x1][y1] = color;
		gridInfo[x2][y2] = OBSTACLE;
	}
	return true;
}


///////////////行动函数//////////////////
void action(int x0, int y0, int x1, int y1, int x2, int y2, int color) {
	gridInfo[x0][y0] = 0;//拿走棋子变成空地
	gridInfo[x1][y1] = color;//落子
	gridInfo[x2][y2] = OBSTACLE;//设置障碍
}


/////////////行动反函数，用于回溯///////////
void deaction(int x0, int y0, int x1, int y1, int x2, int y2, int color) {
	gridInfo[x1][y1] = 0;
	gridInfo[x2][y2] = 0;
	gridInfo[x0][y0] = color;//一定要注意，这里要最后恢复原位，不能先恢复，否则会因为特殊情况被覆盖掉
}


int judgevalue(int color) {
	int result = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (gridInfo[i][j] == color) {
				for (int x = i - 1; x <= i + 1; x++) {
					for (int y = j - 1; y <= j + 1; y++) {
						if (x >= 0 && x < 8 && y >= 0 && y < 8) {
							if (gridInfo[x][y] == 0) {
								result++;
							}
							if(gridInfo[x][y] == color&&!(x==i&&y==j)){
								result--;
							}
							if(gridInfo[x][y] == -color&&!(x==i&&y==j)){
								result++;
							}
						}
					}
				}
			}
			if (gridInfo[i][j] == -color) {
				for (int x = i - 1; x <= i + 1; x++) {
					for (int y = j - 1; y <= j + 1; y++) {
						if (x >= 0 && x < 8 && y >= 0 && y < 8) {
							if (gridInfo[x][y] == 0) {
								result--;
							}
							if(gridInfo[x][y] == -color&&!(x==i&&y==j)){
								result++;
							}
							if(gridInfo[x][y] == color&&!(x==i&&y==j)){
								result--;
							}
						}
					}
				}
			}
		}
	}
	return result;
}///////////////自己写的毫无卵用的评估函数////////


///////////////////集成的kingqueen-bfs搜索////////////////////
void kingandqueen(int myking[][8],int opking[][8],int myqueen[][8],int opqueen[][8],int color){
	//函数功能：生成所有格子的King走法数，存入两个数组中（我方与对方）,color是我方的颜色
	int mycount=0,opcount=0;
	int mx[4],my[4],ox[4],oy[4];
	int queuex[65],queuey[65],qdeep[65],top,end1;
	bool flaging[8][8];


	////////////////////初始化/////////////////////////////
	for(int i=0;i<8;i++)
	for(int j=0;j<8;j++){//一个循环中完成初始化，定位己方与对方棋子的任务
		myking[i][j]=opking[i][j]=myqueen[i][j]=opqueen[i][j]=infinity;//将每个格子初始化为无穷大
		if(gridInfo[i][j]==color){
			mx[mycount]=i;
			my[mycount++]=j;
		}
		else if(gridInfo[i][j]==-color){
			ox[opcount]=i;
			oy[opcount++]=j;
		}
	}



	//////////////先处理kingmove//////////////////////
	for(int z=0;z<4;z++){//遍历己方四个棋子，kingmove为四个棋子到某一空格的极小值，且非空格部分记为无穷
		memset(flaging,0,sizeof(flaging));
		top=0;
		end1=1;
		queuex[0]=mx[z];
		queuey[0]=my[z];//设置队列初始值为某个己方棋子
		qdeep[0]=0;
		flaging[mx[z]][my[z]]=true;//插旗禁行
		while(top!=end1){
			int x=queuex[top];
			int y=queuey[top];
			int deep=qdeep[top];
			myking[x][y]=min(myking[x][y],deep);
			for(int i=0;i<8;i++){
				if(gridInfo[x+dx[i]][y+dy[i]]!=0)continue;
				if(flaging[x+dx[i]][y+dy[i]])continue;
				if(!inMap(x+dx[i],y+dy[i]))continue;//出界，已经走过，有障碍，以上三种情况不考虑，直接continue
				queuex[end1]=x+dx[i];
				queuey[end1]=y+dy[i];
				qdeep[end1++]=deep+1;//将深度信息填入队列
				flaging[x+dx[i]][y+dy[i]]=true;//插旗
			}
			top++;//队首指针后移一格，讨论下一个位置
		}
		myking[mx[z]][my[z]]=infinity;
		//己方棋子所在位置记为无穷
	}
	for(int z=0;z<4;z++){//讨论对手的kingmove
		memset(flaging,0,sizeof(flaging));
		top=0;
		end1=1;
		queuex[0]=ox[z];
		queuey[0]=oy[z];
		qdeep[0]=0;
		flaging[ox[z]][oy[z]]=true;//插旗禁行
		while(top!=end1){
			int x=queuex[top];
			int y=queuey[top];
			int deep=qdeep[top];
			opking[x][y]=min(opking[x][y],deep);
			for(int i=0;i<8;i++){
				if(gridInfo[x+dx[i]][y+dy[i]]!=0)continue;
				if(flaging[x+dx[i]][y+dy[i]])continue;
				if(!inMap(x+dx[i],y+dy[i]))continue;//出界，已经走过，有障碍，以上三种情况不考虑，直接continue
				queuex[end1]=x+dx[i];
				queuey[end1]=y+dy[i];
				qdeep[end1++]=deep+1;//将深度信息填入队列
				flaging[x+dx[i]][y+dy[i]]=true;//插旗
			}
			top++;//队首指针后移一格，讨论下一个位置
		}
		opking[ox[z]][oy[z]]=infinity;
	}









	//////////////////////下面处理queenmove//////////////////
	for(int z=0;z<4;z++){//遍历己方四个棋子
		memset(flaging,0,sizeof(flaging));
		top=0;
		end1=1;
		queuex[0]=mx[z];
		queuey[0]=my[z];//设置队列初始值为某个己方棋子
		qdeep[0]=0;
		flaging[mx[z]][my[z]]=true;//插旗禁行
		while(top!=end1){
			int x=queuex[top];
			int y=queuey[top];
			int deep=qdeep[top];
			myqueen[x][y]=min(myqueen[x][y],deep);
			for(int i=0;i<8;i++){//遍历八个queen方向
				for(int step=1;;step++){//遍历各种距离
					if(flaging[x+dx[i]*step][y+dy[i]*step])continue;//遇到已经走过的地方就跳过
					if(gridInfo[x+dx[i]*step][y+dy[i]*step]!=0)break;
				    if(!inMap(x+dx[i]*step,y+dy[i]*step))break;//此外，出界和遇到障碍都表示这个方向不能再走，break
				    queuex[end1]=x+dx[i]*step;
				    queuey[end1]=y+dy[i]*step;
				    qdeep[end1++]=deep+1;//将深度信息填入队列
				    flaging[x+dx[i]*step][y+dy[i]*step]=true;//插旗
				}
			}
			top++;//队首指针后移一格，讨论下一个位置
		}
		myqueen[mx[z]][my[z]]=infinity;
		//己方棋子所在位置记为无穷
	}
	for(int z=0;z<4;z++){//对方同理
		memset(flaging,0,sizeof(flaging));
		top=0;
		end1=1;
		queuex[0]=ox[z];
		queuey[0]=oy[z];
		qdeep[0]=0;
		flaging[ox[z]][oy[z]]=true;//插旗禁行
		while(top!=end1){
			int x=queuex[top];
			int y=queuey[top];
			int deep=qdeep[top];
			opqueen[x][y]=min(opqueen[x][y],deep);
			for(int i=0;i<8;i++){//遍历八个queen方向
				for(int step=1;;step++){//遍历各种距离
					if(flaging[x+dx[i]*step][y+dy[i]*step])continue;//遇到已经走过的地方就跳过
					if(gridInfo[x+dx[i]*step][y+dy[i]*step]!=0)break;
				    if(!inMap(x+dx[i]*step,y+dy[i]*step))break;//此外，出界和遇到障碍都表示这个方向不能再走，break
				    queuex[end1]=x+dx[i]*step;
				    queuey[end1]=y+dy[i]*step;
				    qdeep[end1++]=deep+1;//将深度信息填入队列
				    flaging[x+dx[i]*step][y+dy[i]*step]=true;//插旗
				}
			}
			top++;//队首指针后移一格，讨论下一个位置
		}
		opqueen[ox[z]][oy[z]]=infinity;
	}

	return;
}

///////////////////面向玩家的估值函数//////////////////////
double evaluation(int color){
	double valuing;
	double t1=0,t2=0,p1=0,p2=0,m1=0,m2=0;
	int mm1,mm2;
	int myking[8][8],opking[8][8],myqueen[8][8],opqueen[8][8];
	kingandqueen(myking,opking,myqueen,opqueen,color);//调用函数生成所有的kingmove与queenmove，保存在数组中 
	for(int i=0;i<8;i++)
	for(int j=0;j<8;j++)
	{
		if(myqueen[i][j]>1)	continue;
		mm1=0;
		for(int p=0;p<8;p++)
		{
			if(!inMap(i+dx[p],j+dy[p])) continue;
			if(gridInfo[i+dx[p]][j+dy[p]]!=0) continue;
			mm1++;
		}
		m1+=mm1/myking[i][j];
	}
	for(int i=0;i<8;i++)
	for(int j=0;j<8;j++)
	{
		if(opqueen[i][j]>1)	continue;
		mm2=0;
		for(int p=0;p<8;p++)
		{
			if(!inMap(i+dx[p],j+dy[p])) continue;
			if(gridInfo[i+dx[p]][j+dy[p]]!=0) continue;
			mm2++;
		}
		m2+=mm2/opking[i][j];
	}
	for(int i=0;i<8;i++)
	for(int j=0;j<8;j++)
	{
		if(myking[i][j]>opking[i][j]) t1+=-1;
		else if(myking[i][j]<opking[i][j]) t1+=1;
		else if(myking[i][j]==infinity) t1+=0;
		else {
			if(currBotColor==1)t1+=0.17;
			else t1-=0.17;
		}
		
		if(myqueen[i][j]>opqueen[i][j]) t2+=-1;
		else if(myqueen[i][j]<opqueen[i][j]) t2+=1;
		else if(myqueen[i][j]==infinity) t2+=0;
		else {
			if(currBotColor==1)t2+=0.17;
			else t2-=0.17;
		}


		p1+=min(1.0,max(-1.0,(opking[i][j]-myking[i][j])/6.0));	
		p2+=2.0*(pow(2.0,-1*myqueen[i][j])-pow(2.0,-1*opqueen[i][j]));
		
	}
	//////////////////以上算出了全部5个实变量//////////////////////////
    
	if(currBotColor==1){
		if(turnID<=7) valuing=0.14*t1+0.37*t2+0.13*p1+0.13*p2+0.20*(m1-m2);
	else if(turnID<=16) valuing=0.3*t1+0.25*t2+0.20*p1+0.20*p2+0.05*(m1-m2);
	else valuing=0.8*t1+0.1*t2+0.05*p1+0.05*p2;
	}
	else{
		if(turnID<=7) valuing=0.14*t1+0.37*t2+0.13*p1+0.13*p2+0.20*(m1-m2);
	else if(turnID<=16) valuing=0.3*t1+0.25*t2+0.20*p1+0.20*p2+0.05*(m1-m2);
	else valuing=0.8*t1+0.1*t2+0.05*p1+0.05*p2;
	}
	

/////////////////////加权赋值//////////////////////
	
	return valuing;//输出评估值
}


/////////下法生成器，对于制定一方，生成对应所有可能的下法，并储存在数组中/////////
int stepgenerator(int color,int beginPos[][2], int possiblePos[][2], int obstaclePos[][2]){
	int posCount2=0;
	for (int i = 0; i < GRIDSIZE; ++i) {
		for (int j = 0; j < GRIDSIZE; ++j) {
			for (int k = 0; k < 8; ++k) {
				for (int delta1 = 1; delta1 < GRIDSIZE; delta1++) {
					int xx = i + dx[k] * delta1;
					int yy = j + dy[k] * delta1;
					if (gridInfo[xx][yy] != 0 || !inMap(xx, yy))
						break;
					for (int l = 0; l < 8; ++l) {
						for (int delta2 = 1; delta2 < GRIDSIZE; delta2++) {
							int xxx = xx + dx[l] * delta2;
							int yyy = yy + dy[l] * delta2;
							if (!inMap(xxx, yyy))
								break;
							if (gridInfo[xxx][yyy] != 0 && !(i == xxx && j == yyy))
								break;
							if (ProcStep(i, j, xx, yy, xxx, yyy, color, true))
							{
								beginPos[posCount2][0] = i;
								beginPos[posCount2][1] = j;
								possiblePos[posCount2][0] = xx;
								possiblePos[posCount2][1] = yy;
								obstaclePos[posCount2][0] = xxx;
								obstaclePos[posCount2++][1] = yyy;
							}
						}
					}
				}

			}
		}
	}
	return posCount2;
}

//////////////////////////集成的pvs-alphabeta负极大值搜索引擎//////////////////////
double alphabeta(int depth,double alpha,double beta,int color){
	finish=clock();
	double time1=(double)(finish-start)/CLOCKS_PER_SEC;
	if(time1>=0.995){
		judgeend=true;
		return 0.0;
	}
	if(judgeend)return 0.0;
	int beginPos[3000][2]={0}, possiblePos[3000][2]={0}, obstaclePos[3000][2]={0};
	int posCount=0;
	bool fFoundPv=false;
	if(depth==0){
		return evaluation(color);
	}
	posCount=stepgenerator(color,beginPos, possiblePos, obstaclePos);//生成所有可能下法
	for(int i=0;i<posCount;i++){//遍历所有可能下法
	    finish=clock();
	    double time2=(double)(finish-start)/CLOCKS_PER_SEC;
	    if(time2>=0.995){
			judgeend=true;
		    return 0.0;
		}
		if(judgeend)return 0.0;
		action(beginPos[i][0], beginPos[i][1], possiblePos[i][0], possiblePos[i][1], obstaclePos[i][0], obstaclePos[i][1], color);//应用走法
        if(color==-currBotColor)turnID++;
		if(fFoundPv){
			value=-alphabeta(depth-1,-alpha-1,-alpha,-color);
			//搜索下一层
			if((value>alpha)&&(value<beta)){//检查失败
				value=-alphabeta(depth-1,-beta,-alpha,-color);//搜索下一层
			}
		}
		else{
			value=-alphabeta(depth-1,-beta,-alpha,-color);//搜索下一层
		}
		deaction(beginPos[i][0], beginPos[i][1], possiblePos[i][0], possiblePos[i][1], obstaclePos[i][0], obstaclePos[i][1], color);//回溯
        if(color==-currBotColor)turnID--;
		finish=clock();
	    double time3=(double)(finish-start)/CLOCKS_PER_SEC;
	    if(time3>=0.995){
			judgeend=true;
		    return 0.0;
		}
		if(judgeend)return 0.0;
		if(value>=beta){
			return beta;
		}
		if(value>alpha){
			if(depth==DEPTH)bestgo=i;
			alpha=value;//保存负极大值
			fFoundPv=true;
		}
	}
	return alpha;
}


///////////////////////////另一版本的pvs，由于在测试中搜索时间过长目前已弃用///////////////////////
double pvssearching(int depth,int alpha,int beta, int color){
	if(depth==0){
		return evaluation(color);
	}
	else{
		int beginPos[3000][2]={0}, possiblePos[3000][2]={0}, obstaclePos[3000][2]={0};
	    int posCount=0;
		posCount=stepgenerator(color,beginPos, possiblePos, obstaclePos);
		if(color==currBotColor){
			//当前是求极大值（我方）
			for(int i=0;i<posCount;i++){
				if(i==0){
					action(beginPos[i][0], beginPos[i][1], possiblePos[i][0], possiblePos[i][1], obstaclePos[i][0], obstaclePos[i][1], color);
					value=pvssearching(depth-1,alpha,beta,-color);
					deaction(beginPos[i][0], beginPos[i][1], possiblePos[i][0], possiblePos[i][1], obstaclePos[i][0], obstaclePos[i][1], color);
				}
				else{
					action(beginPos[i][0], beginPos[i][1], possiblePos[i][0], possiblePos[i][1], obstaclePos[i][0], obstaclePos[i][1], color);
					value=pvssearching(depth-1,alpha,alpha+1,-color);
					deaction(beginPos[i][0], beginPos[i][1], possiblePos[i][0], possiblePos[i][1], obstaclePos[i][0], obstaclePos[i][1], color);
				}
				if(alpha<value&&value<beta){
					action(beginPos[i][0], beginPos[i][1], possiblePos[i][0], possiblePos[i][1], obstaclePos[i][0], obstaclePos[i][1], color);
					value=pvssearching(depth-1,value,beta,-color);
					deaction(beginPos[i][0], beginPos[i][1], possiblePos[i][0], possiblePos[i][1], obstaclePos[i][0], obstaclePos[i][1], color);
				}
				if(value>alpha){
					alpha=value;
					if(depth==DEPTH){
						bestgo=i;
					}
				}
			    if(alpha>=beta)break;
			}
			return alpha;
		}
		else{
			//当前是求极小值（对方）
			for(int i=0;i<posCount;i++){
				if(i==0){
					action(beginPos[i][0], beginPos[i][1], possiblePos[i][0], possiblePos[i][1], obstaclePos[i][0], obstaclePos[i][1], color);
					value=pvssearching(depth-1,alpha,beta,-color);
					deaction(beginPos[i][0], beginPos[i][1], possiblePos[i][0], possiblePos[i][1], obstaclePos[i][0], obstaclePos[i][1], color);
				}
				else{
					action(beginPos[i][0], beginPos[i][1], possiblePos[i][0], possiblePos[i][1], obstaclePos[i][0], obstaclePos[i][1], color);
					value=pvssearching(depth-1,beta-1,beta,-color);
					deaction(beginPos[i][0], beginPos[i][1], possiblePos[i][0], possiblePos[i][1], obstaclePos[i][0], obstaclePos[i][1], color);
				}
				if(alpha<value&&value<beta){
					action(beginPos[i][0], beginPos[i][1], possiblePos[i][0], possiblePos[i][1], obstaclePos[i][0], obstaclePos[i][1], color);
					value=pvssearching(depth-1,alpha,value,-color);
					deaction(beginPos[i][0], beginPos[i][1], possiblePos[i][0], possiblePos[i][1], obstaclePos[i][0], obstaclePos[i][1], color);
				}
				if(value<beta)beta=value;
				if(alpha>=beta)break;
			}
			return alpha;
		}
	}
}

/////////////迭代加深搜索/////////////
void iterative_deepening(){
	start=clock();
	for(int i=1;i<=13;i++){
		DEPTH=i;//设定当前深度
	    alphabeta(DEPTH,-infinity,infinity,currBotColor);
	    if(!judgeend)choice=bestgo;
	    if(judgeend)break;
		if(turnID>=20&&i>=3)break;
	 }
}


//主函数//
int main()
{
    int x0, y0, x1, y1, x2, y2;
	// 初始化棋盘
	gridInfo[0][(GRIDSIZE - 1) / 3] = gridInfo[(GRIDSIZE - 1) / 3][0]
		= gridInfo[GRIDSIZE - 1 - ((GRIDSIZE - 1) / 3)][0]
		= gridInfo[GRIDSIZE - 1][(GRIDSIZE - 1) / 3] = grid_black;
	gridInfo[0][GRIDSIZE - 1 - ((GRIDSIZE - 1) / 3)] = gridInfo[(GRIDSIZE - 1) / 3][GRIDSIZE - 1]
		= gridInfo[GRIDSIZE - 1 - ((GRIDSIZE - 1) / 3)][GRIDSIZE - 1]
		= gridInfo[GRIDSIZE - 1][GRIDSIZE - 1 - ((GRIDSIZE - 1) / 3)] = grid_white;


	
	cin >> turnID;

	// 读入到当前回合为止，自己和对手的所有行动，从而把局面恢复到当前回合
	currBotColor = grid_white; // 先假设自己是白方
	for (int i = 0; i < turnID; i++)
	{
		// 根据这些输入输出逐渐恢复状态到当前回合

		// 首先是对手行动
		cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
		if (x0 == -1)
			currBotColor = grid_black; // 第一回合收到坐标是-1, -1，说明我是黑方
		else
			ProcStep(x0, y0, x1, y1, x2, y2, -currBotColor, false); // 模拟对方落子

																	// 然后是自己当时的行动
																	// 对手行动总比自己行动多一个
		if (i < turnID - 1)
		{
			cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
			if (x0 >= 0)
				ProcStep(x0, y0, x1, y1, x2, y2, currBotColor, false); // 模拟己方落子
		}
	}

	int startX, startY, resultX, resultY, obstacleX, obstacleY;
    int beginPos1[3000][2]={0}, possiblePos1[3000][2]={0}, obstaclePos1[3000][2]={0};
    int posCount1=0;

	posCount1=stepgenerator(currBotColor,beginPos1, possiblePos1,obstaclePos1);//首先产生自己的所有合法棋步


	if (posCount1 > 0)
	{
		iterative_deepening();//通过这一个函数产生最终选择
		startX = beginPos1[choice][0];
	    startY = beginPos1[choice][1];
	    resultX = possiblePos1[choice][0];
	    resultY = possiblePos1[choice][1];
	    obstacleX = obstaclePos1[choice][0];
	    obstacleY = obstaclePos1[choice][1];//实施
	}
	else
	{
		startX = -1;
		startY = -1;
		resultX = -1;
		resultY = -1;
		obstacleX = -1;
		obstacleY = -1;
	}
	

	// 决策结束，输出结果
	cout << startX << ' ' << startY << ' ' << resultX << ' ' << resultY << ' ' << obstacleX << ' ' << obstacleY << endl;

	return 0;
	
}