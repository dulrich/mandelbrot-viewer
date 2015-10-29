// mandelbrot viewer: curses mandelbrot explorer
// Copyright (C) 2015  David Ulrich
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as published
// by the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
// 
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <ncurses.h>
#include <stdio.h>

int render(int zoom,int shift_x,int shift_y,int width,int height) {
	int x_scale = 25 * zoom;
	int y_scale = 10 * zoom;
	
	shift_x = (shift_x * zoom) + width * (zoom - 1);
	shift_y = shift_y * zoom;
	
	float i,j,r;
	int k;
	
	float x,y;
	y = -height + shift_y;
	
	erase();
	
	int c = 0;
	while(c++,y++ < (height - 1 + shift_y)) {
		move(c,0);
		refresh();
		
		for(
			x = 0 + shift_x;
			x++ < 2 * width + shift_x;
			addch(" .:-;!/>)|&IH%*#"[k&15])
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

int main() {
	int zoom = 1;
	
	int shift_x = -11;
	int shift_y = 0;
	
	// if you have a larger terminal...
	// should get curses window size
	int width = 50;
	int height = 20;
	
	int c = 0;
	
	initscr();
	
	noecho();
	cbreak();
	keypad(stdscr,TRUE);
	
	do {
		if (c == 'x' || c == 'X' || c == 'q' || c == 'Q') {
			break;
		}
		else if (c == '+') {
			zoom++;
		}
		else if (c == '-') {
			zoom--;
		}
		else if (c == KEY_UP) {
			shift_y--;
		}
		else if (c == KEY_DOWN) {
			shift_y++;
		}
		else if (c == KEY_LEFT) {
			shift_x--;
		}
		else if (c == KEY_RIGHT) {
			shift_x++;
		}
		
		getmaxyx(stdscr,height,width);
		
		if (zoom < 1) zoom = 1;
		
		render(zoom,shift_x,shift_y,width/2,height/2);
		
		refresh();
		c = getch();
	} while(c);
	
	endwin();
	
	return 0;
}
