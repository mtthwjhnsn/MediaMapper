#version 410

#pragma include "Common/random.glsl"

uniform vec3      iResolution;           // viewport resolution (in pixels)
uniform float     iGlobalTime;           // shader playback time (in seconds)
uniform float     iTimeDelta;            // render time (in seconds)
uniform int       iFrame;                // shader playback frame
uniform float     iChannelTime[4];       // channel playback time (in seconds)
uniform vec3      iChannelResolution[4]; // channel resolution (in pixels)
uniform vec4      iMouse;                // mouse pixel coords. xy: current (if MLB down), zw: click
uniform sampler2D iChannel0;          // input channel. XX = 2D/Cube
uniform vec4      iDate;                 // (year, month, day, time in seconds)
uniform float     iSampleRate;

// inputs
in vec2 vTexCoord;

// outputs
out vec4 outputColor;

// params
#define PI 3.14159265359

uniform Params {
    vec3 dc;
    vec3 amp;
    vec3 freq;
    vec3 phase;
    float num_bands;
    float animate_speed;
    int palette_lfo_red;
    int palette_lfo_green;
    int palette_lfo_blue;
    int amp_lfo_type;
    int freq_lfo_type;
    int phase_lfo_type;
    float amp_lfo_speed;
    float freq_lfo_speed;
    float phase_lfo_speed;
    float amp_lfo_amp;
    float freq_lfo_amp;
    float phase_lfo_amp;
    float amp_cycle_speed;
    float freq_cycle_speed;
    float phase_cycle_speed;
}params;

//--------- LFO's --------------
// FLOATS
float tri(float x) {
    return asin(sin(x))/(PI/2.);
}
float puls(float x) {
    return (floor(sin(x))+0.5)*2.;
}
float saw(float x) {
    return (fract((x/2.)/PI)-0.5)*2.;
}
float noise(float x) {
    return (fract(sin((x*2.) *(12.9898+78.233)) * 43758.5453)-0.5)*2.;
}
// VEC3
vec3 tri(vec3 x) {
    return vec3(asin(sin(x))/(PI/2.));
}
vec3 puls(vec3 x) {
    return vec3((floor(sin(x))+0.5)*2.);
}
vec3 saw(vec3 x) {
    return vec3((fract((x/2.)/PI)-0.5)*2.);
}
vec3 noise(vec3 x) {
    return vec3((fract(sin((x*2.) *(12.9898+78.233)) * 43758.5453)-0.5)*2.);
}


float lfo(int type, float x){
    if(type == 0) return sin(x);
    else if(type == 1) return tri(x);
    else if(type == 2) return saw(x);
    else if(type == 3) return puls(x);
    else if(type == 4) return noise(x);
    else return 0.0;
}
vec3 lfo(int type, vec3 x){
    if(type == 0) return cos(x);
    else if(type == 1) return tri(x);
    else if(type == 2) return saw(x);
    else if(type == 3) return puls(x);
    else if(type == 4) return noise(x);
    else return vec3(0.0);
}

//--------- Colour Palette
vec3 pal( in float t, in vec3 a, in vec3 b, in vec3 c, in vec3 d )
{
//    return a + b*lfo(params.palette_lfo_type, (6.28318*(c*t+d)));

  vec3 out_pal = vec3(a.x + b.x*lfo(params.palette_lfo_red, (6.28318*(c.x*t+d.x))),
                      a.y + b.y*lfo(params.palette_lfo_green, (6.28318*(c.y*t+d.y))),
                      a.z + b.z*lfo(params.palette_lfo_blue, (6.28318*(c.z*t+d.z))));

  return out_pal;

}

void main( void )
{
    //vec2 p = vec2(gl_FragCoord.xy - 0.5* iResolution.xy) / iResolution.y;
    vec2 p = gl_FragCoord.xy / iResolution.xy;

    // animate
    float t = iGlobalTime;
    p.x += (params.animate_speed*3.0)*t;

    // compute colors
    float idx = ceil(p.y*params.num_bands) / params.num_bands;

    vec3 col = pal( p.x, params.dc,
                   (idx*lfo(params.amp_lfo_type,t*params.amp_lfo_speed)*params.amp_lfo_amp) + params.amp + (t*(params.amp_cycle_speed*0.1)),
                   (idx*lfo(params.freq_lfo_type,t*params.freq_lfo_speed)*params.freq_lfo_amp) + params.freq + (t*(params.freq_cycle_speed*0.1)) ,
                   (idx*lfo(params.phase_lfo_type,t*params.phase_lfo_speed)*params.phase_lfo_amp) + params.phase + (t*(params.phase_cycle_speed*0.1)));

    // band
    float f = fract(p.y*params.num_bands);
    // borders
    col *= smoothstep( 0.49, 0.47, abs(f-0.5) );
    // shadowing
    col *= 0.5 + 0.5*sqrt(4.0*f*(1.0-f));
    // dithering
    //col += (1.0/255.0)*texture( iChannel0, gl_FragCoord.xy/iChannelResolution[0].xy ).xyz;

    outputColor = vec4( col, 1.0 );
}
