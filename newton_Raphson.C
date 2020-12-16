#include<stdio.h>
#include<conio.h>
#include<math.h>

double fun(double y,int i,int a[]){
    double r=0.0;   
    for(;i>=0;i--)
        r=r+(a[i])*(pow(y,i));
    return r;
}
double der(double y,int i,int a[]){
    double r=0.0;   
    for(;i>0;i--)
        r=r+(a[i])*i*(pow(y,i-1));
    return r;
} 
    
int main(){
    int deg,arr[10],itr=0,maxitr,i;
    double fun(double,int,int*),der(double,int,int*),x,x0=0.0,b,fa,fb,fx;
{
    printf("\n---------------------------------------------------------  Newton Raphson  --------------------------------------------------------");
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
            x0=i;
            b=i+1;
            break;
        }
        else if(fa>0&&fb>0){
            for(i=-1;;i--){
                fa=fun(i-1,deg,arr);
                fb=fun(i,deg,arr);
                if(fa<0&&fb>0){
                    x0=i-1;
                    b=i;
                    goto mid;
                }
            }
        }
         else if(fa>0&&fb<0){
            b=i;
            x0=i+1;
            fx=fa;
            fa=fb;
            fb=fx;
            goto mid;
        }
    }
    mid:
        printf("\n\n  x0=%fl",x0);
}    
    //x0
{
    for(i=0;i<maxitr;i++){
        fa=fun(x0,deg,arr);  //fa here for f(x0)
        fb=der(x0,deg,arr);  //fb here for f'(x0)
        x=x0-(fa/fb);
        
        itr++;
        printf("\n\n\tx0=%fl and x=%fl   \t f(x0)=%fl and f'(x)=%fl  ",x0,x,fa,fb);
        
        if(x==x0)
            break;
        x0=x;
    }
}
    //Newton Raphson   
    end:
        printf("\n\n  Root Calculated is %lf in %d iterations.",x,itr);
        printf("\n\n\n");
    return 0;
}
  

    

  