# version 400

layout (location = 0) in vec3 vPos;
layout (location = 1) in vec2 vTexCoord;

out vec2 TexCoord;

void main ()
 {
   TexCoord = vTexCoord;
   gl_Position = vec4 ( vPos.x, vPos.y, vPos.z, 1.0 );
 }
