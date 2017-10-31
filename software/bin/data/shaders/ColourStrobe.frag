vec2 rotate( vec2 inVec, float angle )
{
 	mat4 rotMatrix = mat4
    (
    	cos( angle ),	-sin( angle ),	0,	0,
        sin( angle ), 	cos( angle ),	0,	0,
        0,				0,				1,	0,
        0,				0,				0,	1    );
    
    return ( vec4( inVec, 0.0, 1.0 ) * rotMatrix ).xy;
}

void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
	vec2 uv = fragCoord.xy / iResolution.xy;
    
    float offsetVal = iTime;
    
    vec2 uvR = uv;
    uvR.y /= uvR.x;
    uvR = rotate( uvR, offsetVal );
    
    vec2 uvG = uv;
    uvG.x /= uvG.y;
    uvG = rotate( uvG, -offsetVal );
    
    vec2 uvB = uv;
    uvB.xy -= sin( offsetVal );
    
    fragColor = vec4( uvR.y * 0.5 + 0.5, uvG.y * 0.5 + 0.5, uvB.y * 0.5 + 0.5, 1.0 );
}