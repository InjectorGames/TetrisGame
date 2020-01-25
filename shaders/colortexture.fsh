uniform sampler2D texture;
varying highp vec2 o_textureCoordinate;

void main(void)
{
    gl_FragColor = texture2D(texture, o_textureCoordinate);
}
