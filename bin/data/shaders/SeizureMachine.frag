void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
    float x = 1. * abs(sin(iTime * 10000.));
    fragColor = vec4(x);
    
}