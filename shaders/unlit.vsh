attribute highp vec4 vertexPosition;
uniform highp mat4 modelViewProjection;

void main(void)
{
    gl_Position = modelViewProjection * vec4(vertexPosition, 1.0f);
}
