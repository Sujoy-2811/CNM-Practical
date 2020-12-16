#include<stdio.h>
#include<conio.h>
#include<math.h>

double fun(double y,int i,int a[]){
    double r=0.0;   
    for(;i>=0;i--)
        r=r+(a[i])*(pow(y,i));
    return r;
} 
    
int main(){
    int deg,arr[10],itr=0,maxitr,i;
    double fun(double,int,int*),x,x1,a=0.0,b=0.0,fa,fb,fx;
    
{
    printf("\n----------------------------------------------------------  Regula Falsi  ----------------------------------------------------------");
    printf("\n\n  Enter the Highest Order: ");
    scanf("%d",&deg);
    printf("\n");
    
    for(i=deg;i>=0;i--){
        printf("  Enter Coeffecient of x%d: ",i);
        scanf("%d",&arr[i]);
    }
    printf("\n  Enter the Maximum No. of Iterations: ");
    scanf("%d",&maxitr);
}
    //Input
    
{
    for(i=0;;i++){
        fa=fun(i,deg,arr);
        fb=fun(i+1,deg,arr);
        printf("\n  f(%d)=%fl and f(%d)=%fl",i,fa,i+1,fb);

        if(fa==0){
            x=i;
            goto end;
        }
        if(fb==0){
            x=i+1;
            goto end;
        }            
        if(fa<0&&fb>0){
            a=i;
            b=i+1;
            break;
        }
        else if(fa>0&&fb>0){
            for(i=-1;;i--){
                fa=fun(i-1,deg,arr);
                fb=fun(i,deg,arr);
                if(fa<0&&fb>0){
                    a=i-1;
                    b=i;
                    goto mid;
                }
            }
        }
        else if(fa>0&&fb<0){
            b=i;
            a=i+1;
            fx=fa;
            fa=fb;
            fb=fx;
            goto mid;
        }
    }
    mid:
        printf("\n\n  f(a)=%fl and f(b)=%fl",fa,fb);
        printf("\n\n  a=%fl and b=%fl",a,b);
}    
    //a & b
{  
    for(i=0;i<maxitr;i++){
        x=((a*fb)-(b*fa))/(fb-fa);
        fx=fun(x,deg,arr);
        itr++;
        printf("\n\n\ta=%fl and b=%fl   \t f(a)=%fl and f(b)=%fl    \t x=%fl and f(x)=%fl",a,b,fa,fb,x,fx);
        if(fx>0){
            fb=fx;
            b=x;
        }
        else{
            fa=fx;
            a=x;
        }
        if(x==x1)
            break;
        x1=x;
    }
}
    //Regula Falsi   
    end:
        printf("\n\n  Root Calculated is %lf in %d iterations.",x,itr);
        printf("\n\n\n");
    return 0;
}
  

    

  