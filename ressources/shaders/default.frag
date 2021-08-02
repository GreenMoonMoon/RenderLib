#version 460 core

out vec4 FragColor;

void main()
{
    vec3 color = vec3(gl_FragCoord.xy, 0.0);
    FragColor = vec4(color, 1.0);
}