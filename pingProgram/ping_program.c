#include <windows.h>
#include <stdio.h>

#define PING_BUTTON_1 1
#define PING_BUTTON_2 2
#define PING_BUTTON_3 3
#define PING_BUTTON_4 4
#define PING_BUTTON_5 5

#define CMD 11
#define SYSTEM 22
#define FIREWALL 33
#define REMOTE 44
#define DEVMGMT 55
#define INETCPL 66

#define SETTING_BUTTON 100

#define PING_ADRESS_1 10
#define PING_ADRESS_2 20
#define PING_ADRESS_3 30
#define PING_ADRESS_4 40
#define PING_ADRESS_5 50

#define SET_ADAPTER 200
#define SET_IP 300
#define SET_SUBNET 400
#define SET_GATEWAY 500
#define SET_P_DNS 600
#define SET_S_DNS 700

#define NET_APPLY 800
#define NET_DHCP 900
#define DNS_APPLY 1000
#define DNS_DHCP 1100

char str1[128]; // ID_ADRESS_1 data
char str2[128]; // ID_ADRESS_2 data
char str3[128]; // ID_ADRESS_3 data
char str4[128]; // ID_ADRESS_4 data
char str5[128]; // ID_ADRESS_5 data

char str6[128]; // SET_ADAPTER data
char str7[128]; // SET_IP data
char str8[128]; // SET_SUBNET data
char str9[128]; // SET_GATEWAY data
char str10[128]; // SET_P_DNS data
char str11[128]; // SET_S_DNS data

char AD_MySelf_Comment[]="made by : blog.naver.com/jogilsang";
char AD_KEYWORD[]="기타 네트워크 키워드";
char AD_Setting_Comment[]="내 컴퓨터 네트워크설정";
char AD_Apply_Comment[]="Apply";
char AD_DHCP_Comment[]="DHCP";
char AD_ICMP_Comment[]="다중 ICMP 프로토콜 체크";

char AD_Network_Name[]="Net-Adapter";
char AD_Network_Ip[]="ip(v4)"; 
char AD_Network_Subnet[]="subnet";
char AD_Network_Gateway[]="GateWay";
char AD_Network_P_DNS[]="Primary-DNS";
char AD_Network_S_DNS[]="Second-DNS";

char TITLE[]="만능 네트워크 도구 - made by jogilsang";

char netsh_dns1[]="netsh interface ip set dnsservers \"";
char netsh_dns2[]="netsh interface ip add dns \"";
char netsh_ip[]="netsh interface ip set address \"";

char ping[]="ping ";
char Bowl[];
char empty[];
char statics[]=" static ";
char primary[]=" primary";
char secondary[]=" index=2";

HWND hEdit1;
HWND hEdit2;
HWND hEdit3;
HWND hEdit4;
HWND hEdit5;

HWND hEdit6;
HWND hEdit7;
HWND hEdit8;
HWND hEdit9;
HWND hEdit10;

HWND hEdit11;

HWND hEdit12;
HWND hEdit13;
HWND hEdit14;
HWND hEdit15;
HWND hEdit16;
HWND hEdit17;

HWND hEdit18;
HWND hEdit19;

HWND hEdit20;
HWND hEdit21;

HWND hEdit22;
HWND hEdit23;
HWND hEdit24;
HWND hEdit25;
HWND hEdit26;
HWND hEdit27;



HDC hdc; // temp

PAINTSTRUCT ps; // temp

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
char szClassName[ ] = "WindowsApp";

int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nFunsterStil)

{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default color as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           TITLE,       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           350,       /* Windows decides the position */
           200,       /* where the window ends up on the screen */
           544,                 /* The programs width */
           450,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nFunsterStil);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
	 	  case WM_CREATE:
		hEdit1=CreateWindow("edit",NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | 
		       ES_AUTOHSCROLL,10,50,120,25,hwnd,(HMENU)PING_ADRESS_1,NULL,NULL);
		hEdit2=CreateWindow("edit",NULL,WS_CHILD | WS_VISIBLE | WS_BORDER | 
 	           ES_AUTOHSCROLL,10,90,120,25,hwnd,(HMENU)PING_ADRESS_2,NULL,NULL);
		hEdit3=CreateWindow("edit",NULL,WS_CHILD | WS_VISIBLE | WS_BORDER | 
		       ES_AUTOHSCROLL,10,130,120,25,hwnd,(HMENU)PING_ADRESS_3,NULL,NULL);
		hEdit4=CreateWindow("edit",NULL,WS_CHILD | WS_VISIBLE | WS_BORDER | 
		       ES_AUTOHSCROLL,10,170,120,25,hwnd,(HMENU)PING_ADRESS_4,NULL,NULL);
		hEdit5=CreateWindow("edit",NULL,WS_CHILD | WS_VISIBLE | WS_BORDER | 
		       ES_AUTOHSCROLL,10,210,120,25,hwnd,(HMENU)PING_ADRESS_5,NULL,NULL);
		
		hEdit6=CreateWindow("button","Click Me",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			135,50,100,25,hwnd,(HMENU)PING_BUTTON_1,NULL,NULL);
		hEdit7=CreateWindow("button","Click Me",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			135,90,100,25,hwnd,(HMENU)PING_BUTTON_2,NULL,NULL);
		hEdit8=CreateWindow("button","Click Me",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			135,130,100,25,hwnd,(HMENU)PING_BUTTON_3,NULL,NULL);
		hEdit9=CreateWindow("button","Click Me",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			135,170,100,25,hwnd,(HMENU)PING_BUTTON_4,NULL,NULL);
		hEdit10=CreateWindow("button","Click Me",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			135,210,100,25,hwnd,(HMENU)PING_BUTTON_5,NULL,NULL);
			
		hEdit11=CreateWindow("button",AD_Setting_Comment,WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			300,10,200,25,hwnd,(HMENU)SETTING_BUTTON,NULL,NULL);	
			
		hEdit12=CreateWindow("edit",NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | 
		       ES_AUTOHSCROLL,390,50,120,25,hwnd,(HMENU)SET_ADAPTER,NULL,NULL);
		hEdit13=CreateWindow("edit",NULL,WS_CHILD | WS_VISIBLE | WS_BORDER | 
 	           ES_AUTOHSCROLL,390,90,120,25,hwnd,(HMENU)SET_IP,NULL,NULL);
		hEdit14=CreateWindow("edit",NULL,WS_CHILD | WS_VISIBLE | WS_BORDER | 
		       ES_AUTOHSCROLL,390,130,120,25,hwnd,(HMENU)SET_SUBNET,NULL,NULL);
		hEdit15=CreateWindow("edit",NULL,WS_CHILD | WS_VISIBLE | WS_BORDER | 
		       ES_AUTOHSCROLL,390,170,120,25,hwnd,(HMENU)SET_GATEWAY,NULL,NULL);
		hEdit16=CreateWindow("edit",NULL,WS_CHILD | WS_VISIBLE | WS_BORDER | 
		       ES_AUTOHSCROLL,390,250,120,25,hwnd,(HMENU)SET_P_DNS,NULL,NULL);
        hEdit17=CreateWindow("edit",NULL,WS_CHILD | WS_VISIBLE | WS_BORDER | 
		       ES_AUTOHSCROLL,390,290,120,25,hwnd,(HMENU)SET_S_DNS,NULL,NULL);
		       
        hEdit18=CreateWindow("button",AD_Apply_Comment,WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			390,210,55,25,hwnd,(HMENU)NET_APPLY,NULL,NULL);
	 
	    hEdit19=CreateWindow("button",AD_DHCP_Comment,WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			455,210,55,25,hwnd,(HMENU)NET_DHCP,NULL,NULL);
			
		hEdit20=CreateWindow("button",AD_Apply_Comment,WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			390,330,55,25,hwnd,(HMENU)DNS_APPLY,NULL,NULL);
	 
	    hEdit21=CreateWindow("button",AD_DHCP_Comment,WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			455,330,55,25,hwnd,(HMENU)DNS_DHCP,NULL,NULL);
			
		hEdit22=CreateWindow("button","MS - DOS",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			10,290,120,25,hwnd,(HMENU)CMD,NULL,NULL);
		hEdit23=CreateWindow("button","시스템구성",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			10,330,120,25,hwnd,(HMENU)SYSTEM,NULL,NULL);
		hEdit24=CreateWindow("button","방화벽 설정",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			10,370,120,25,hwnd,(HMENU)FIREWALL,NULL,NULL);
		hEdit25=CreateWindow("button","원격접속",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			135,290,100,25,hwnd,(HMENU)REMOTE,NULL,NULL);
		hEdit26=CreateWindow("button","장치관리자",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			135,330,100,25,hwnd,(HMENU)DEVMGMT,NULL,NULL);
		hEdit27=CreateWindow("button","인터넷옵션",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			135,370,100,25,hwnd,(HMENU)INETCPL,NULL,NULL);
		
		return 0;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		 {
		case SETTING_BUTTON:
			 system("ncpa.cpl"); // 제어판->모든 제어판 항목 -> 네트워크 연결 
             break;
             
	    case CMD:
			 system("cmd"); // CMD 
             break;
			 
	    case SYSTEM:
			 system("control /name Microsoft.System"); // SYSTEM
             break;	 
			 
	    case FIREWALL:
			 system("firewall.cpl"); // FIREWALL 
             break;	 
			 
  	    case REMOTE:
			 system("mstsc"); // REMOTE
             break;	 
			 
	    case DEVMGMT:
			 system("devmgmt.msc"); // DEVMGMT
             break;	
			 
	    case INETCPL:
			 system("inetcpl.cpl"); // DEVMGMT
             break;	 	 	   
        
        case NET_APPLY:
		     if(strlen(str6)==0) {
			    MessageBox(hwnd,"Please fill in the contents. ","Button",MB_OK);
			     break;
				 }
		   	 
			 
			 if(strlen(str7)==0 || strlen(str8)==0) {
			     if(strlen(str9)!=0) {
				 					 
			     }
			    MessageBox(hwnd,"Please fill in the contents. ","Button",MB_OK);
				}
			 else
			 {	 
				 strcpy(Bowl,netsh_ip);  // Bowl = netsh interface ip set address \"
               
				    
				 strcat(netsh_ip,str6);  // 
				 strcat(netsh_ip," ");				 
                 strcat(netsh_ip, "static "); // netsh interface ip set address "로컬 영역 연결" static            
				 strcat(netsh_ip,str7); // netsh interface ip set address "로컬 영역 연결" static 주소 
				 strcat(netsh_ip," ");
				 strcat(netsh_ip,str8); // netsh interface ip set dnsservers "로컬 영역 연결" static 주소 서브넷 
				 strcat(netsh_ip," ");
				  // netsh interface ip set dnsservers "로컬 영역 연결" static 주소 서브넷\n
				 strcat(netsh_ip,str9);// netsh interface ip set dnsservers "로컬 영역 연결" static 주소 서브넷 GW
				 MessageBox(hwnd,netsh_ip,"Button",MB_OK);
				 system(netsh_ip);  
   	             strcpy(netsh_ip,Bowl); // netsh_ip = "netsh interface ip set address \"
				 strcpy(Bowl,empty);     // BOwl = ""
		          
		     }
				 
             break;
             //netsh interface ip set address "로컬 영역 연결" static 192.168.0.10 255.255.255.0 192.168.0.1
        case NET_DHCP: // apply 버튼(1) -> 네트워크 주소 자동할당 설정(DHCP) 
 		     system("netsh interface ip set address name=\"로컬 영역 연결\" source=dhcp");
		     break;
        
		case DNS_APPLY: 
			 //에디터 두개에 값이 있는지 확인
			 // 1,2 있으면 둘다 system명령어
			 // 1만 있으면 하나만 system 명령어
			 // 2만 있으면 하나만 system 명령어
			  
			  if     (strlen(str10)==0 && strlen(str11)==0) { // 둘다 없으면 에러.
			      MessageBox(hwnd,"Please fill in the contents. ","Button",MB_OK);
			     }
			  else if(strlen(str10)!=0 && strlen(str11)==0) {// 주DNS만 설정 
                 strcpy(Bowl,netsh_dns1);  // Bowl = "netsh interface ip set dnsservers "
                 strcat(str6,"\"");
				 strcat(netsh_dns1,str6);  // netsh interface ip set dnsservers "로컬 영역 연결"
                 strcat(netsh_dns1,statics); // netsh interface ip set dnsservers "로컬 영역 연결" static 
				 strcat(netsh_dns1,str10); // netsh interface ip set dnsservers "로컬 영역 연결" static
				 strcat(netsh_dns1,primary); // netsh interface ip set dnsservers "로컬 영역 연결" static 주소 primary 
   	             system(netsh_dns1);  
   	             MessageBox(hwnd,netsh_dns1,"Button",MB_OK);
   	             strcpy(netsh_dns1,Bowl); // netsh_dns = "netsh interface ip set dnsservers "
				 strcpy(Bowl,empty);     // BOwl = ""	             
				 }
			  else if(strlen(str10)==0 && strlen(str11)!=0) { // 보조DNS만 설정 
                 strcpy(Bowl,netsh_dns2);  // Bowl = "netsh interface ip set dnsservers "
                 strcat(str6,"\" ");
				 strcat(netsh_dns2, str6);  // netsh interface ip set dnsservers "로컬 영역 연결"
				 strcat(netsh_dns2, str11); // netsh interface ip set dnsservers "로컬 영역 연결" 
   	             strcat(netsh_dns2, secondary); // netsh interface ip add dns "로컬 영역 연결" index=2
				 system(netsh_dns2); 
				 MessageBox(hwnd,netsh_dns2,"Button",MB_OK); 
   	             strcpy(netsh_dns2,Bowl); // netsh_dns = "netsh interface ip set dnsservers "
				 strcpy(Bowl,empty);     // BOwl = ""	             
				 } // netsh interface ip add dns “로컬 영역 연결” 설정IP
	               // netsh interface ip add dns "로컬 연결 영역" 10.123.12.1 index=2
			  else {                                         // 둘다 설정 
			     strcpy(Bowl,netsh_dns1);  // Bowl = "netsh interface ip set dnsservers "
                 strcat(str6,"\"");
				 strcat(netsh_dns1,str6);  // netsh interface ip set dnsservers "로컬 영역 연결"
                 strcat(netsh_dns1,statics); // netsh interface ip set dnsservers "로컬 영역 연결" static 
				 strcat(netsh_dns1,str10); // netsh interface ip set dnsservers "로컬 영역 연결" static
				 strcat(netsh_dns1,primary); // netsh interface ip set dnsservers "로컬 영역 연결" static 주소 primary 
   	             system(netsh_dns1);  
   	             strcpy(netsh_dns1,Bowl); // netsh_dns = "netsh interface ip set dnsservers "
				 strcpy(Bowl,empty);     // BOwl = ""
				  
				 strcpy(Bowl,netsh_dns2);  // Bowl = "netsh interface ip set dnsservers "
                 strcat(str6,"\" ");
				 strcat(netsh_dns2, str6);  // netsh interface ip set dnsservers "로컬 영역 연결"
				 strcat(netsh_dns2, str11); // netsh interface ip set dnsservers "로컬 영역 연결" 
   	             strcat(netsh_dns2, secondary); // netsh interface ip add dns "로컬 영역 연결" index=2
				 system(netsh_dns2);  
   	             strcpy(netsh_dns2,Bowl); // netsh_dns = "netsh interface ip set dnsservers "
				 strcpy(Bowl,empty); 
				  
				   }
			 
             break;
             //netsh interface ip set dnsservers "로컬 영역 연결" static 168.126.63.1 primary
             
        case DNS_DHCP: // apply 버튼(2) -> 네트워크 DNS 주소 자동할당 설정(DHCP) 
 		     system("netsh interface ip set dns name=\"로컬 영역 연결\" source=dhcp");
			 break;
        
		case SET_ADAPTER:  
			 switch (HIWORD(wParam)) {
			case EN_CHANGE:
				GetWindowText(hEdit12,str6,128);
				SetWindowText(hwnd,str6);					
	          } 
		     break;
		case SET_IP:
			 switch (HIWORD(wParam)) {
			case EN_CHANGE:
				GetWindowText(hEdit13,str7,128);
				SetWindowText(hwnd,str7);					
	          }
             break;
		case SET_SUBNET:
			 switch (HIWORD(wParam)) {
			case EN_CHANGE:
				GetWindowText(hEdit14,str8,128);
				SetWindowText(hwnd,str8);					
	          }
             break;
		case SET_GATEWAY:
			 switch (HIWORD(wParam)) {
			case EN_CHANGE:
				GetWindowText(hEdit15,str9,128);
				SetWindowText(hwnd,str9);					
	          }
		     break;
		case SET_P_DNS:
			 switch (HIWORD(wParam)) {
			case EN_CHANGE:
				GetWindowText(hEdit16,str10,128);
				SetWindowText(hwnd,str10);					
	          }
             break;
		case SET_S_DNS:
			 switch (HIWORD(wParam)) {
			case EN_CHANGE:
				GetWindowText(hEdit17,str11,128);
				SetWindowText(hwnd,str11);					
	          }
		     break;
		     
		case PING_BUTTON_1:
			 if(strlen(str1)==0) 
		       	 MessageBox(hwnd,"Please fill in the contents. ","Button",MB_OK);
			 else { 
			 	 strcpy(Bowl,ping);  // Bowl = "ping "
                 strcat(ping,str1);  // ping = "ping str1" 
   	             system(ping);
				 strcpy(ping,Bowl);  // ping = "ping "
   	             strcpy(Bowl,empty); // Bowl = ""
				        // edit에 기재된 값에 ping을 붙여서 출력 
				 }
		     break;		     
        case PING_BUTTON_2:
 	         if(strlen(str2)==0) 
		       	 MessageBox(hwnd,"Please fill in the contents. ","Button",MB_OK);
			 
   	             else { 
			 	 strcpy(Bowl,ping);  // Bowl = "ping "
                 strcat(ping,str2);  // ping = "ping str1" 
   	             system(ping);
				 strcpy(ping,Bowl);  // ping = "ping "
   	             strcpy(Bowl,empty);       // edit에 기재된 값에 ping을 붙여서 출력 
				 }
			 break;
        case PING_BUTTON_3:
 	         if(strlen(str3)==0) 
		       	 MessageBox(hwnd,"Please fill in the contents. ","Button",MB_OK);
		
   	             else { 
			 	 strcpy(Bowl,ping);  // Bowl = "ping "
                 strcat(ping,str3);  // ping = "ping str1" 
   	             system(ping);
				 strcpy(ping,Bowl);  // ping = "ping "
   	             strcpy(Bowl,empty);       // edit에 기재된 값에 ping을 붙여서 출력 
				 }
			 break;
        case PING_BUTTON_4:
 	         if(strlen(str4)==0) 
		       	 MessageBox(hwnd,"Please fill in the contents. ","Button",MB_OK);
		
   	             else { 
			 	 strcpy(Bowl,ping);  // Bowl = "ping "
                 strcat(ping,str4);  // ping = "ping str1" 
   	             system(ping);
				 strcpy(ping,Bowl);  // ping = "ping "
   	             strcpy(Bowl,empty);     // edit에 기재된 값에 ping을 붙여서 출력 
				 }
			 break;
        case PING_BUTTON_5:
 	         if(strlen(str5)==0) 
		       	 MessageBox(hwnd,"Please fill in the contents. ","Button",MB_OK);
		
   	             else { 
			 	 strcpy(Bowl,ping);  // Bowl = "ping "
                 strcat(ping,str5);  // ping = "ping str1" 
   	             system(ping);
				 strcpy(ping,Bowl);  // ping = "ping "
   	             strcpy(Bowl,empty);       // edit에 기재된 값에 ping을 붙여서 출력 
				 }
			 break;
			 
		case PING_ADRESS_1: 
			switch (HIWORD(wParam)) {
			case EN_CHANGE:
				GetWindowText(hEdit1,str1,128);
				SetWindowText(hwnd,str1);					
	          }
            break;
        case PING_ADRESS_2:
			switch (HIWORD(wParam)) {
                case EN_CHANGE:
				GetWindowText(hEdit2,str2,128);
				SetWindowText(hwnd,str2);					
	          }
            break;
        case PING_ADRESS_3:
			switch (HIWORD(wParam)) {
		     	case EN_CHANGE:
				GetWindowText(hEdit3,str3,128);
				SetWindowText(hwnd,str3);					
	          }
            break;
        case PING_ADRESS_4:
			switch (HIWORD(wParam)) {
			case EN_CHANGE:
				GetWindowText(hEdit4,str4,128);
				SetWindowText(hwnd,str4);					
	          }
            break;
        case PING_ADRESS_5:
			switch (HIWORD(wParam)) {
			case EN_CHANGE:
				GetWindowText(hEdit5,str5,128);
				SetWindowText(hwnd,str5);					
	          }
            break;
		 
		 }
		return 0;
		

              
	  
//GetDlgItemText		
        case WM_PAINT:
			 hdc=BeginPaint(hwnd,&ps);
			 
			 TextOut(hdc,290,390,AD_MySelf_Comment,strlen(AD_MySelf_Comment));
			 TextOut(hdc,30,10,AD_ICMP_Comment,strlen(AD_ICMP_Comment));
			 TextOut(hdc,40,250,AD_KEYWORD,strlen(AD_KEYWORD));
			 
			 TextOut(hdc,300,50,AD_Network_Name,strlen(AD_Network_Name)); // 네트워크 어댑터명 
			 TextOut(hdc,300,90,AD_Network_Ip,strlen(AD_Network_Ip)); // ip(v4) 
			 TextOut(hdc,300,130,AD_Network_Subnet,strlen(AD_Network_Subnet)); // subnet
			 TextOut(hdc,300,170,AD_Network_Gateway,strlen(AD_Network_Gateway)); // GateWay
			
			 TextOut(hdc,300,250,AD_Network_P_DNS,strlen(AD_Network_P_DNS)); // P_DNS
			 TextOut(hdc,300,290,AD_Network_S_DNS,strlen(AD_Network_S_DNS)); // S_DNS
			 
			 EndPaint(hwnd,&ps);
		 	 return 0;
	
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
