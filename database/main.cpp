//database �� ���� opencv310 / vc14

#include "GetTimeT.h" 
#include "db.h" //db�� �����ֱ�
#include "dbinsert.h"
#include "GetDistance.h"
#include "select.h"
#include <time.h>
int main(int, char**)
{
	int index = 0;
	char buf[256];
	char buf2[256];
	char buf3[256];
	char buf4[256];
	char buf5[256];

	int a = 1;  //1��ī�޶�
	int a2 = 2; //2��ī�޶�
	int a3 = 3; //3��ī�޶�
	int a4 = 4; //4��ī�޶�
	int a5 = 5; //5��ī�޶�
	char *b; //��¥ �ð�
	char c[256] = "'web_cam1'";
	char c2[256] = "'web_cam2'";
	char c3[256] = "'web_cam3'";
	char c4[256] = "'web_cam4'";
	char c5[256] = "'web_cam5'";
	char d_lat[256] = "'35.889147'";
	char d_lng[256] = "'128.610314'";
	char d2_lat[256] = "'35.894074'";
	char d2_lng[256] = "'128.606904'";
	char d3_lat[256] = "'35.902965'";
	char d3_lng[256] = "'128.618665'";
	char d4_lat[256] = "'35.897390'"; //�뱸�����б�
	char d4_lng[256] = "'128.620502'";
	char d5_lat[256] = "'35.902381'";//������б�
	char d5_lng[256] = "'128.622762'";
	char f[256] = "' '";
	//string f = "car_num";
	char g[256] = "'on'";
	char g2[256] = "'off'";
	int k;
	tagPT first_loc; // ó�� ������ �߰ߵ� ��ġA
	tagPT cam1_loc;
	tagPT cam2_loc;
	//��ġA
	first_loc.y = 36.364808;
	first_loc.x = 127.379525;

	//ī�޶�1�� ��ġ
	cam1_loc.y = 36.364772;
	cam1_loc.x = 127.390275;

	//ī�޶�2�� ��ġ
	cam2_loc.y = 36.363972;
	cam2_loc.x = 127.410275;


	double Dis1 = GetDistance(first_loc, cam1_loc);
	double Dis2 = GetDistance(first_loc, cam2_loc);
	double Dis = 0;
	
	/////////////	
	Mat frameMat;
	Mat frameMat2;
	Mat frameMat3;
	Mat frameMat4;
	Mat frameMat5;
	VideoCapture videoCapture(0);
	VideoCapture videoCapture2(1);
	VideoCapture videoCapture3(2);
	VideoCapture videoCapture4(3);
	VideoCapture videoCapture5(4);

	if (!videoCapture.isOpened())
	{
		printf("ù��° ī�޶� ���� �����ϴ�. \n");
	}
	if (!videoCapture2.isOpened())
	{
		printf("�ι�° ī�޶� ���� �����ϴ�. \n");
	}
	if (!videoCapture3.isOpened())
	{
		printf("����° ī�޶� ���� �����ϴ�. \n");
	}
	if (!videoCapture4.isOpened())
	{
		printf("�׹�° ī�޶� ���� �����ϴ�. \n");
	}
	if (!videoCapture5.isOpened())
	{
		printf("�ټ���° ī�޶� ���� �����ϴ�. \n");
	}
	

	namedWindow("ī�޶�1", WINDOW_AUTOSIZE);
	namedWindow("ī�޶�2", WINDOW_AUTOSIZE);
	namedWindow("ī�޶�3", WINDOW_AUTOSIZE);
	namedWindow("ī�޶�4", WINDOW_AUTOSIZE);
	namedWindow("ī�޶�5", WINDOW_AUTOSIZE);
	while (1)
	{
		//�ð��޾ƿ���
		struct tm *t;
		time_t timer;

		timer = time(NULL);    // ���� �ð��� �� ������ ���
		t = localtime(&timer); // �� ������ �ð��� �и��Ͽ� ����ü�� �ֱ�
		b = timeToString(t);

		//��ĸ���κ��� �� �������� �о��  
		videoCapture.read(frameMat);
		videoCapture2.read(frameMat2);
		videoCapture3.read(frameMat3);
		videoCapture4.read(frameMat4);
		videoCapture5.read(frameMat5);

        //ȭ�鿡 ������
		imshow("ī�޶�1", frameMat);
		imshow("ī�޶�2", frameMat2);
		imshow("ī�޶�3", frameMat3);
		imshow("ī�޶�4", frameMat4);
		imshow("ī�޶�5", frameMat5);

		//�̹����� ����  
		sprintf(buf, "Z:/HDD1/cam1/img_%06d.jpg", index);
		sprintf(buf2, "Z:/HDD1/cam2/img_%06d.jpg", index);
		sprintf(buf3, "Z:/HDD1/cam3/img_%06d.jpg", index);
		sprintf(buf4, "Z:/HDD1/cam4/img_%06d.jpg", index);
		sprintf(buf5, "Z:/HDD1/cam5/img_%06d.jpg", index);

		cout << buf << endl;

		imwrite(buf, frameMat);
		imwrite(buf2, frameMat2);
		imwrite(buf3, frameMat3);
		imwrite(buf4, frameMat4);
		imwrite(buf5, frameMat5);

		videoCapture.open(0);
		videoCapture2.open(1);
		videoCapture3.open(2);
		videoCapture4.open(3);
		videoCapture5.open(4);

		if (!videoCapture.isOpened())
		{
			printf("ù��° ī�޶� ���� �����ϴ�. \n");
			//db(a, b, c, Dis, buf, f, g2);

		}
		else {
			db(a, b, c, d_lat, d_lng, buf, f, g);
		}
		if (!videoCapture2.isOpened())
		{
			printf("�ι�° ī�޶� ���� �����ϴ�. \n");
			//db(a2, b, c2, Dis, buf2, f, g2);

		}
		else {
			db(a2, b, c2, d2_lat, d2_lng, buf2, f, g);
		}
		if (!videoCapture3.isOpened())
		{
			printf("����° ī�޶� ���� �����ϴ�. \n");
			//db(a3, b, c3, Dis, buf3, f, g2);

		}
		else {
			db(a3, b, c3, d3_lat, d3_lng, buf3, f, g);
		}
		if (!videoCapture4.isOpened())
		{
			printf("�׹�° ī�޶� ���� �����ϴ�. \n");
			//db(a3, b, c3, Dis, buf3, f, g2);

		}
		else {
			db(a4, b, c4, d4_lat, d4_lng, buf4, f, g);
		}
		if (!videoCapture5.isOpened())
		{
			printf("�ټ���° ī�޶� ���� �����ϴ�. \n");
			//db(a3, b, c3, Dis, buf3, f, g2);

		}
		else {
			db(a5, b, c5, d5_lat, d5_lng, buf5, f, g);
		}


		index++;

		if (index == 999999) index = 0;

		if (waitKey(25) == 27) break; //ESCŰ ������ ����  
	}

	return 0;
}
