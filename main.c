#include <stdio.h>

int main() {
	int k;
	
	// STUFF TO CHANGE
	
	int zoom = 1;
	
	int x_shift = -11;
	int y_shift = 0;
	
	// if you have a larger terminal...
	int width = 50;
	int height = 20;
	
	// END STUFF TO CHANGE
	
	int x_scale = 25 * zoom;
	int y_scale = 10 * zoom;
	
	x_shift = (x_shift * zoom) + width * (zoom - 1);
	y_shift = y_shift * zoom;
	
	float i,j,r,x,y=-height+y_shift;
	
	while(puts(""),y++ < (height - 1 + y_shift)) {
		for(
			x = 0 + x_shift;
			x++ < 2 * width + x_shift;
			putchar(" .:-;!/>)|&IH%*#"[k&15])
		) {
			for(
				i=k=r=0;
				j=r*r-i*i-2+x/x_scale,i=2*r*i+y/y_scale,j*j+i*i<11&&k++<111
				;r=j
			);
		}
	}
	
	return 0;
}
