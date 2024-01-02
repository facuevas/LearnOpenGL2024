#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;
uniform float offset;


void main()
{
    /**
    * We can flip the Texture Coordinate to render the texture in a different direction.
    * Note that this isn't the solution because I added a position uniform to make the smiley face move.
    * If you set pos to a fixed value of 1.0f, it will flip.
    */
    FragColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), offset);
}