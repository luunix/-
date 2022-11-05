//#include <graphics.h>
//#include <time.h>
//#include <stdlib.h>
//#include <stdio.h>
//
////一些特定数值，先把他用符号定义出来：宏定义
////窗口大小
//#define WIDTH 1000
//#define HEIGHT 600
////鱼的大小
////最小的
//#define FISH_MIN_W 50
//#define FISH_MAX_H 20
////鱼的数目
//#define FISH_MAX_NUMS 7
////定时器的数目
//#define TIMER_MAX  10
////边界
//#define BOARD 100
////朝向
//#define ASPECT_LEFT 0
//#define ASPECT_RIGHT 2
////角色
//#define ROLE 0
//
//struct Fish
//{
//	//鱼的坐标
//	int x;
//	int y;
//	int dir;	//鱼的方向
//	int type;	//鱼的类型
//	//鱼的宽度和高度
//	int w;
//	int h;
//};
//struct Fish fish[Fish_MAX_NUMS]；//等效struct Fish fish[7];
//	//加载资源--->批量加载
//	IMAGE background;	//背景图
//IMAGE fishIMG[7][4];//合理设计 0 1：左边的背景和掩码 2 3 右边的背景和掩码
//
//
//void intFish(int type)
//{
//	if (type == ROLE)
//	{
//		//角色的属性
//		fish[type].x = 0;
//		fish[type].y = 0; 
//		fish[type].dir = ASPECT_RIGHT;
//		fish[type].type = ROLE;
//		fish[type].w = FISH_MIN_W +50;
//		fish[type].h = FISH_MIN_H +50;
//	}
//	else
//	{
//		//其他鱼是随机产生
//		fish[type].type = rand() % (FISH_MAX_NUMS - 1) + 1;//rand()%6+1 [0,5],[1,6]	
//		int dir = rand() % 10 > 5 ? ASPECT_LEFT : ASPECT_RIGHT;
//		fish[type].dir = dir;
//		fish[type].y = rand() % 50 * 10 + 50;
//		fish[type].x = dir == ASPECT_LEFT ? rand() % BOARD + WIDTH : -1 * rand() % BOARD;
//		fish[type].w = FISH_MIN_W + 10 * type;
//		fish[type].h = FISH_MIN_H + 10 * type;
//	}
//}
//void LoadResources()
//{
//	loadimage(&background, "./res/background.jpg", WIDTH, HEIGHT);
//	char fileName[20] = { "" };
//	for (int i = 0; i < FISH_MAX_NUMS; i++)
//	{
//		InitFish(i);
//		for (int j = 0; j < 4; j++)
//		{
//		//fishIMG[i][0]	左边掩码图
//		//fishIMG[i][1]	左边的背景图
//		//fishIMG[i][2]	右边的掩码图
//		//fishIMG[i][3]	右边的背景图
//			switch (j)
//			{
//				case 0;
//					sprintf(fileName, "./Res/%d_left_y.jpg", i);
//					break;
//				case 1;
//					sprintf(fileName, "./Res/%d_left.jpg", i);
//					break;
//				case 2;
//					sprintf(fileName, "./Res/%d_right_y.jpg", i);
//					break;
//				case 3;
//					sprintf(fileName, "./Res/%d_right.jpg", i);
//					break;
//			}
//			loadimage(&fishIMG[i][j], fileName, fish[i].w, fish[i].h);
//		}
//	}
//}
//
////绘制过程
//void DrawFsih()
//{
//	for (int i = 0; i < FISH_MAX_NUMS; i++0)
//	{
//		putimage(fsih[i].x, fish[i].y, &fishIMG[i][fish[i].dir], SRCAND);
//		putimage(fsih[i].x, fish[i].y, &fishIMG[i][fish[i].dir+1], SRCPAINT);
//	}
//}
//void ResetFish(
//	{
//		for (inti = 1; i < FISH_MAX_NUMS; i++)
//		{
//			switch (fish[i].dir)
//			{
//			case ASPECT_LEFT:
//					if (fish[i].x < -BOARD)
//					{
//						InitFish(i);
//					}
//					break;
//			case ASPECT_RIGHT:
//				if(fish[i].x > WIDTH + BOARD)
//				{
//					InitFish(i);
//				}
//				break;
//			}
//		}
//	}
////定时器
//int OnTimer(int duration, int id)
//	{
//		static int startTime[TIMER_MAX];
//		int endTime = clock();
//		if (endTime - startTime[id] >= duration)
//		{
//			startTime[id] = endTime;
//			return 1;
//		}
//		return 0;
//	}
//	//控制过程
//	//自动控制---->怪物
//	void MoveFish()
//	{
//		for (intr i = 1; i < FISH_MAX_NUMS; i++)
//		{
//			switch (fish[i].dir)
//			{
//			case ASPECT_LEFT:
//				fish[i].x--; 
//				break;
//			case ASPECT_RIGHT:
//				fi[is.x++;
//				break;
//			}
//		}
//	}
//
//	//人为控制---->角色
//	void Control(
//		{
//			if (GetAsyncKeyState(VK_LEFT) && fish[ROLE].x > 0)
//			{
//				fish[ROLE].x--;
//				fish[ROLE].dir = ASPECT_LEFT;
//			}
//			if (GetAsyncKeyState(VK_RIGHT) && fish[ROLE].x <WIDTH-fish[ROLE].w)
//			{
//				fish[ROLE].x++;
//				fish[ROLE].dir = ASPECT_RIGHT;
//			}
//			if (GetAsyncKeyState(VK_UP) && fish[ROLE].y > 0)
//			{
//				fish[ROLE].y--;
//			}
//			if (GetAsyncKeyState(VK_DOWN) && fish[ROLE].y <HEIGHT-fish[ROLE].h)
//			{
//				fish[ROLE].y++;
//			}
//		}
//		int EatFish(int type)		//假设吃的是type这条鱼
//		{
//			//两个矩形相交
//			//左上角求最大值
//			int MinX = max(fish[ROLE].x, fish[type].x);
//			int MinY = max(fish[ROLE].y, fish[type].y);
//			//右下角求最小值
//			int MaxX = min(fish[ROLE].x + fsih[ROLE].w, fish[type].x + fish[ROLE].w);
//			int MaxY = min(fish[ROLE].y + fish[ROLE].h, fish[type].y + fish[ROLE].h);
//			if (minX > MaxX || MinY > MaxY)
//			{
//				return 0;		//不相交
//			}
//			else
//			{
//				//面积判断大小
//				if (fish[ROLE].w * fsih[ROLE].h > fish[type].w * fsih[type].h)
//				{
//					InitFish(type);
//					return 0;
//				}
//				else
//				{
//					return 1;
//				}
//			}
//		}
//		int GameOver()
//		{
//			for (int i = 1; i < FISH_MAX_NUMS; i++)
//			{
//				if (EatFish(i) == 1)
//					return 1;
//			}
//			return 0;
//		}
//		int main()
//		{
//			srand((unsigned int)time(NULL));
//			HWND hwnd = initgraph(WIDTH, HEIGHT);
//			LoadResources();
//			BeginBatchDraw();
//			while(1)
//			{
//				putimage(0, 0, &background);
//				DrawFish();
//				FlushBatchDraw();
//				Control();
//				if (OnTimer(10, 0))
//					MoveFish();
//				ResetFish();
//				if (GameOver() == 1)
//				{
//					MessageBox(hwnd, "GameOver", "You Losse", MB_OK);
//					break;
//				}
//			}
//			EndBatchDraw();
//			closegraph();
//			return 0;
//		}