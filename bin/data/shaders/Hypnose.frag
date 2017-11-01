void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
    vec2 coord = fragCoord.xy;
    vec2 center = iResolution.xy /2.0;
    float dist = length(center - coord);
    float circlesOut = cos(dist/7.0 - iTime*6.0);
    circlesOut *= 5.0;
    float circlesIn = cos(dist/7.0 + iTime*6.0);
    circlesIn *= 5.0;
    circlesIn = clamp(circlesIn,0.0,1.0);
    circlesOut = clamp(circlesOut,0.0,1.0);
    float edge = clamp(dist-100.0,0.0,1.0);
    circlesOut *= edge;
    circlesIn *= 1.0-edge;
    float c = circlesOut + circlesIn;
	fragColor = vec4(c,c,c,0.0);
}