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
	// ===== SET OPTIONS ===== //
	float iter = 150.0;
	float scale = 1.50;
	
	vec2 c_orig;
	
	float peak = 0.800;
	float peak_i = 1.0 - peak;
	
	vec3 rgb_falloff = vec3(
		1.0,
		2.0,
		4.0
	);
	// ===== END OPTIONS ===== //
	
	float aspect = u_resolution.x / u_resolution.y;
	
	vec2 c = (2.0 * gl_FragCoord.xy - u_resolution.xy) / u_resolution.xy * scale;
	
	c.x *= aspect;
	
	// c_orig = c; // mandelbrot
	c_orig = vec2(-0.275, -0.645); // julia seed
	
	float i;
	
	for (i = 0.0; i < iter; ++i) {
		float tempx = c.x;

		c.x = (tempx * tempx) - (c.y * c.y) + c_orig.x;
		c.y = 2.0 * tempx * c.y + c_orig.y;
		
		if ((c.x * c.x) + (c.y * c.y) > 4.0) break;
	}
	
	vec4 color;
	float ratio = i / iter;
	
	if (ratio < peak) {
		color = vec4(
			clamp(1.0 - (peak - ratio) / (peak / rgb_falloff.x), 0.0, 1.0),
			clamp(1.0 - (peak - ratio) / (peak / rgb_falloff.y), 0.0, 1.0),
			clamp(1.0 - (peak - ratio) / (peak / rgb_falloff.z), 0.0, 1.0),
			1.0
		);
	}
	else {
		color = vec4(
			clamp(1.0 + (peak - ratio) / (peak_i / rgb_falloff.x), 0.0, 1.0),
			clamp(1.0 + (peak - ratio) / (peak_i / rgb_falloff.y), 0.0, 1.0),
			clamp(1.0 + (peak - ratio) / (peak_i / rgb_falloff.z), 0.0, 1.0),
			1.0
		);
	}
	
	gl_FragColor = color;
}
