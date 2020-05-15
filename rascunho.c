#include <stdio.h>
int main (){
int gatos, animais, X;
scanf("%d%d%d", &gatos,&animais,&X );
if (X >= gatos && animais + gatos >= X )
    printf("YES");
else
	printf("NO");

	return 0;
}
