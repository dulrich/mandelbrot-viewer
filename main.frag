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
	
	vec3 peak = vec3(
		0.200,
		0.400,
		0.800
	);
	
	vec3 rgb_falloff = vec3(
		1.0,
		1.0,
		1.0
	);
	// ===== END OPTIONS ===== //
	
	float aspect = u_resolution.x / u_resolution.y;
	
	vec2 c = (2.0 * gl_FragCoord.xy - u_resolution.xy) / u_resolution.xy * scale;
	
	c.x *= aspect;
	
	// c_orig = c; // mandelbrot
	c_orig = vec2(-0.390, -0.647); // julia seed
	
	float i;
	
	for (i = 0.0; i < iter; ++i) {
		float tempx = c.x;

		c.x = (tempx * tempx) - (c.y * c.y) + c_orig.x;
		c.y = 2.0 * tempx * c.y + c_orig.y;
		
		if ((c.x * c.x) + (c.y * c.y) > 4.0) break;
	}
	
	vec4 color;
	float ratio = i / iter;
	
	vec3 dir_sign = vec3(1.0, 1.0, 1.0);
	vec3 peak_i = vec3(1.0, 1.0, 1.0) - peak;
	
	if (ratio < peak.x) {
		dir_sign.x = -1.0;
		peak_i.x = peak.x;
	}
	
	if (ratio < peak.y) {
		dir_sign.y = -1.0;
		peak_i.y = peak.y;
	}
	
	if (ratio < peak.z) {
		dir_sign.z = -1.0;
		peak_i.z = peak.z;
	}
	
	color = vec4(
		clamp(1.0 + (dir_sign.x * (peak.x - ratio) / (peak_i.x / rgb_falloff.x)), 0.0, 1.0),
		clamp(1.0 + (dir_sign.y * (peak.y - ratio) / (peak_i.y / rgb_falloff.y)), 0.0, 1.0),
		clamp(1.0 + (dir_sign.z * (peak.z - ratio) / (peak_i.z / rgb_falloff.z)), 0.0, 1.0),
		1.0
	);
	
	gl_FragColor = color;
}
