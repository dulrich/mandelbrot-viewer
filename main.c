// mandelbrot viewer: curses mandelbrot explorer
// Copyright (C) 2015  David Ulrich
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as published
// by the Free Software Foundation, version 3 of the License.
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
#include <tgmath.h>

int render(short color,long double zoom,long double shift_x,long double shift_y,int width,int height) {
	long long x_scale = 25 * fabs(zoom);
	long long y_scale = 10 * fabs(zoom);
	
	shift_x = shift_x + width * (zoom - 1);
	
	long double i,j,r;
	int k,kk;
	kk = 0;
	
	long double x,y;
	y = -height + shift_y;
	
	erase();
	
	int c = 0;
	while(c++,y++ < (height - 1 + shift_y)) {
		move(c,0);
		
		for(
			x = 0 + shift_x;
			x++ < 2 * width + shift_x;
		) {
			for(
				i=k=r=0;
				j=r*r-i*i-2+x/x_scale,i=2*r*i+y/y_scale,j*j+i*i<11&&k++<111
				;r=j
			);
			if (color && (k&15) != kk) {
				attroff(COLOR_PAIR(k&15));
				attron(COLOR_PAIR(k&15));
				kk = k&15;
			}
			addch(" .:-;!/>)|&IH%*#"[k&15]);
		}
	}
	
	return 0;
}

int main() {
	long double zoom = 1;
	long double zoom_factor = 1.25;
	
	long double shift_x = -11;
	long double shift_y = 0;
	
	// if you have a larger terminal...
	// should get curses window size
	int width = 50;
	int height = 20;
	
	int c = 0;
	short color;
	
	initscr();
	
	noecho();
	cbreak();
	keypad(stdscr,TRUE);
	
	
	color = COLORS >= 256;
	
	if (color) {
		start_color();
		
		init_color(0,62*0,0,0);
		init_color(1,62*1,0,0);
		init_color(2,62*2,0,0);
		init_color(3,62*3,0,0);
		init_color(4,62*4,0,0);
		init_color(5,62*5,0,0);
		init_color(6,62*6,0,0);
		init_color(7,62*7,0,0);
		init_color(8,62*8,0,0);
		init_color(9,62*9,0,0);
		init_color(10,62*10,0,0);
		init_color(11,62*11,0,0);
		init_color(12,62*12,0,0);
		init_color(13,62*13,0,0);
		init_color(14,62*14,0,0);
		init_color(15,62*15,0,0);
		
		init_pair(0,0,0);
		init_pair(1,1,0);
		init_pair(2,2,0);
		init_pair(3,3,0);
		init_pair(4,4,0);
		init_pair(5,5,0);
		init_pair(6,6,0);
		init_pair(7,7,0);
		init_pair(8,8,0);
		init_pair(9,9,0);
		init_pair(10,10,0);
		init_pair(11,11,0);
		init_pair(12,12,0);
		init_pair(13,13,0);
		init_pair(14,14,0);
		init_pair(15,15,0);
	}
	
	do {
		if (c == 'x' || c == 'X' || c == 'q' || c == 'Q') {
			break;
		}
		else if (c == '+') {
			zoom *= zoom_factor;
			
			shift_x *= zoom_factor;
			shift_y *= zoom_factor;
		}
		else if (c == '-') {
			zoom /= zoom_factor;
			
			shift_x /= zoom_factor;
			shift_y /= zoom_factor;
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
		
		render(color,zoom,shift_x,shift_y,width/2,height/2);
		
		refresh();
		
		c = getch();
	} while(c);
	
	endwin();
	
	return 0;
}
