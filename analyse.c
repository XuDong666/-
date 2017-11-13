#include<stdio.h>
#include<string.h>
char prog[500],token[8],ch;
static char *kpWords[16]={"if","while","for","return","main","switch","case","break","int","char","float","double","scanf","printf","void","include"};
int syn,p,m,n,sum;

void input(){
	  sum=0;  
      
    for(m=0;m<8;m++)  {
	token[m++]=0;
	}
          
      
    ch=prog[p++];  
    m=0;  
          
    while((ch==' ')||(ch=='\n')||(ch=='\t'))  
        ch=prog[p++];  
      
    if(((ch<='z')&&(ch>='a'))||((ch<='Z')&&(ch>='A')))  
     {   
        while(((ch<='z')&&(ch>='a'))||((ch<='Z')&&(ch>='A'))||((ch>='0')&&(ch<='9')) || (ch=='.'))  
        {  
            token[m++]=ch;  
            ch=prog[p++];  
        }  
          
        p--;  
        syn=1;  
  
        for(n=0;n<16;n++)  
        if(strcmp(token,kpWords[n])==0)  
        {   
            syn=2;  
            break;  
        }  
     }  
     else if((ch>='0')&&(ch<='9'))  
     {   
        while((ch>='0')&&(ch<='9'))  
        {  
            sum=sum*10+ch-'0';  
            ch=prog[p++];  
        }  
        p--;  
        syn=3;  
    }  
    else   
    {  	
        switch(ch)  
        {  
        case '<':  
            token[m++]=ch;  
            ch=prog[p++];  
            if(ch=='=')  
            {   
                syn=17;  
                token[m++]=ch;  
            }  
            else  
            {    
                syn=16;  
                p--;  
            }  
        break;  
  
        case '>':  
            token[m++]=ch;  
            ch=prog[p++];  
            if(ch=='=')  
            {  
                syn=15;  
				token[m++]=ch;  
            }  
            else  
            {   
                syn=14;  
                p--;  
            }  
        break;  
  
        case '+':  
            token[m++]=ch;  
            ch=prog[p++];  
            if(ch=='+')  
            {  
                syn=5;  
                token[m++]=ch;  
            }  
            else  
            {  
                syn=4;  
                p--;  
            }  
        break;  
  
        case '-':  
            token[m++]=ch;  
            ch=prog[p++];  
            if(ch=='-')  
            {  
                syn=7;  
                token[m++]=ch;  
            }  
            else  
            {   
                syn=6;  
                p--;  
            }  
        break;  
  
        case '!':  
            ch=prog[p++];  
            if(ch=='=')  
            {   
                syn=13;  
                token[m++]=ch;  
            }  
            else  
            {   
                syn=13;  
                p--;  
            }  
        break;  
  
        case '=':  
            token[m++]=ch;  
            ch=prog[p++];  
            if(ch=='=')  
            {  
                syn=12;  
                token[m++]=ch;  
            }  
            else  
            {  
                syn=11;  
                p--;  
            }  
        break;  
  
        case '*':  
            token[m++]=ch;  
            ch=prog[p++];  
            if(ch=='*')  
            {  
                syn=9;  
                token[m++]=ch;  
            }  
            else  
            {  
                syn=8;  
                p--;  
            } 
        break;  
  
        case '/':  
            syn=10;  
            token[m++]=ch;  
        break;  
  
        case '(':   
            syn=18;  
            token[m++]=ch;  
        break;  
  
        case ')':  
            syn=19;  
            token[m++]=ch;  
        break;  
  
        case '{':   
            syn=20;  
            token[m++]=ch;  
        break;  
  
        case '}':   
            syn=21;  
            token[m++]=ch;  
        break;  
  		case '[':   
            syn=22;  
            token[m++]=ch;  
        break;  
  
        case ']':   
            syn=23;  
            token[m++]=ch;  
        break; 
        case ';':  
            syn=25;  
            token[m++]=ch;  
        break;  

        case '#':   
            syn=24;  
            token[m++]=ch;  
        break;  
  
        case ':':  
            syn=26;  
            token[m++]=ch;  
        break;
		case '%':  
            syn=27;  
            token[m++]=ch;  
        break;
		case '\'':  
            syn=28;  
            token[m++]=ch;  
        break;
		case '\"':  
            syn=29;  
            token[m++]=ch;  
        break; 
		case ',':
			syn=30;
			token[m++]=ch;
			break; 	
  		case '~':  
            syn=0;  
            token[m++]=ch;  
        break; 
        default:  
            syn=-1;  
        break;  
        }  
    }  
        token[m++]='\0';
}
int main(){
	char fileName[8];
	char file[8];
	FILE *fp1;
	FILE *fp2;
	
	p=0;
	printf("请输入文件名:\n");
	scanf("%s",fileName);
	printf("请输入生成文件名:\n");
	scanf("%s",file);
    strcat(file,".txt");
	fp2=fopen(file,"w");
	fp1=fopen(fileName,"r");
	if(fp1==NULL){
	 	printf("文件打开失败！");
		return 0;
	}
	while((ch=fgetc(fp1))!=EOF){
		 prog[p++]=ch;
	}
	fclose(fp1);
	prog[p]=' ';
	prog[p+1]='~';
	p=0;
	do{
		input();
		switch(syn){
				case 3:  
                    fprintf(fp2,"( %-10d%5d )\n",sum,syn);  
                break;  
                  
                case -1:  
                    fprintf(fp2,"你输入的字符串错误！\n");  
                case 0:
                	break;
                break;  
                  
                default:   
                fprintf(fp2,"( %-10s%5d )\n",token,syn);  
                break;  
		}
		
	}while(syn!=0);
	fclose(fp2);
	printf("生成文件.txt");
 
	return 0; 
} 

