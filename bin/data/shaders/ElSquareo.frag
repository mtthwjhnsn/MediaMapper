void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
	vec2 uv = fragCoord.xy / iResolution.xy;
    vec2 centered = uv - vec2(0.5, 0.5);
    
	fragColor = texture(iChannel0, uv);
    
    float square = abs(sin(iTime)) * 0.5;
    
    if (abs(centered.x) > square || abs(centered.y) > square) {
        fragColor.r = abs(sin(iTime));
    }
    
    float secondTime = iTime + 2.0;
    square = abs(sin(secondTime)) * 0.5;

    
     if (abs(centered.x) > square || abs(centered.y) > square) {
        fragColor.g = abs(cos(iTime));
    }
    
    float thirdTime = secondTime + 2.0;
    square = abs(sin(thirdTime)) * 0.5;

    
     if (abs(centered.x) > square || abs(centered.y) > square) {
        fragColor.b = abs(tan(iTime));
    }    
}