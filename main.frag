// mandelbrot viewer: glsl fractal shader
// Copyright (C) 2016  David Ulrich
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

// run with `glslViewer main.frag`

uniform vec2 u_resolution;

void main() {
	float iter = 150.0;
	float scale = 1.25;
	
	float aspect = u_resolution.x / u_resolution.y;
	
	vec2 c = (2.0 * gl_FragCoord.xy - u_resolution.xy) / u_resolution.xy * scale;
	
	c.x *= aspect;
	
	vec2 c_orig = c;
	
	float i;
	
	for (i = 0.0; i < iter; ++i) {
		float tempx = c.x;

		c.x = (tempx * tempx) - (c.y * c.y) + c_orig.x;
		c.y = 2.0 * tempx * c.y + c_orig.y;
		
		if ((c.x * c.x) + (c.y * c.y) > 4.0) break;
	}
	
	gl_FragColor = vec4(i == iter ? 0.0 : i / iter, 0.0, 0.0, 1.0);
}
