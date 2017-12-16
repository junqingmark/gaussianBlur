#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

// texture sampler
uniform sampler2D texture1;
uniform float offset[5] = float[](0.0, 1.0, 2.0, 3.0, 4.0);
uniform float weight[5][5] = float[][]( 0.003765,	0.015019,	0.023792,	0.015019,	0.003765,
0.015019,	0.059912,	0.094907,	0.059912,	0.015019,
0.023792,	0.094907,	0.150342,	0.094907,	0.023792,
0.015019,	0.059912,	0.094907,	0.059912,	0.015019,
0.003765,	0.015019,	0.023792,	0.015019,	0.003765);

void main()
{
    FragColor = texture2D( texture1, vec2(gl_FragCoord)/800.0 );
	for (int i=0; i<5; i++) 
    {

		for(int j = 0; j < 5; j++)
		{
			FragColor += texture2D( texture1, ( vec2(gl_FragCoord)+vec2(0.0, offset[i]) )/800.0 ) * weight[i][j];
		FragColor += texture2D( texture1, ( vec2(gl_FragCoord)-vec2(0.0, offset[i]) )/800.0 ) * weight[i][j];
		FragColor += texture2D( texture1, ( vec2(gl_FragCoord)+vec2(offset[i], 0.0) )/800.0 ) * weight[i][j];
		FragColor += texture2D( texture1, ( vec2(gl_FragCoord)-vec2(offset[i], 0.0) )/800.0 ) * weight[i][j];
		}
		
	}
	
}