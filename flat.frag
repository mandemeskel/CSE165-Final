# version 400

in vec2 TexCoord;

uniform sampler2D Tex1;

out vec4 fColor;

void main() 
 { 
   fColor = texture2D(Tex1, TexCoord);
 } 
