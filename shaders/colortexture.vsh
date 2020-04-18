attribute highp vec3 vertexPosition;
attribute highp vec2 textureCoordinate;
varying highp vec2 o_textureCoordinate;

void main(void)
{
    gl_Position = vec4(vertexPosition, 1.0f);
    o_textureCoordinate = textureCoordinate;
}
