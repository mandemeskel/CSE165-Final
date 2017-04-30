#pragma once
# include <vector>
# include <string>
# include <gsim/gs_vec.h>
# include <gsim/gs_image.h>
# include "ogl_tools.h"

using namespace std;

class Square : public GlObjects
{
	// temporary buffer objects
	vector<GsVec> vertices;
	vector<GsVec2> tex_coords;

	int num_vertices;

	// texture objects
	GsImage img;
	gsuint img_id;

public:
	Square()
	{
		num_vertices = 0;
	}

	void init(const GlProgram& prog)
	{
		// Define buffers needed:
		set_program(prog);
		gen_vertex_arrays(1); // will use 1 vertex array
		gen_buffers(2);       // will use 2 buffers: coordinates & tex. coords
		uniform_locations(1); // program uses 1 uniform for texture
		uniform_location(0, "Tex1");

		if (!img.load("../bg.png")) { std::cout << "COULD NOT LOAD IMAGE!\n";}
		else {
			glGenTextures(1, &img_id); // generated ids start at 1
			glBindTexture(GL_TEXTURE_2D, img_id);
			glTexImage2D(GL_TEXTURE_2D, 0, 4, img.w(), img.h(), 0, GL_RGBA, GL_UNSIGNED_BYTE, img.data());
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
			glGenerateMipmap(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, 0);
			glBindVertexArray(0);
		}
	}

	void build()
	{

		vertices.clear(); tex_coords.clear(); // set size to zero, just in case

		vertices.push_back(GsVec(-0.5, 0.5, 0.0)); // top left 
		tex_coords.push_back(GsVec2(0, 0));

		vertices.push_back(GsVec(0.5, 0.5, 0.0)); // top right
		tex_coords.push_back(GsVec2(1, 0));

		vertices.push_back(GsVec(0.5, -0.5, 0.0)); // bot right
		tex_coords.push_back(GsVec2(1, 1));

		vertices.push_back(GsVec(0.5, -0.5, 0.0)); // bot right
		tex_coords.push_back(GsVec2(1, 1));

		vertices.push_back(GsVec(-0.5, -0.5, 0.0)); // bot left
		tex_coords.push_back(GsVec2(0, 1));

		vertices.push_back(GsVec(-0.5, 0.5, 0.0)); // top left
		tex_coords.push_back(GsVec2(0, 0));


		glBindBuffer(GL_ARRAY_BUFFER, buf[0]);
		glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(float)*vertices.size(), &vertices[0], GL_STATIC_DRAW);

		glBindBuffer(GL_ARRAY_BUFFER, buf[1]);
		glBufferData(GL_ARRAY_BUFFER, 2 * sizeof(float)*tex_coords.size(), &tex_coords[0], GL_STATIC_DRAW);

		// save size so that we can free our buffers and later draw the OpenGL arrays:
		num_vertices = vertices.size(); 
		vertices.clear(); tex_coords.clear();

		changed = false;
	}

	void draw()
	{

		glUseProgram(prog);
		glBindTexture(GL_TEXTURE_2D, img_id);

		glBindBuffer(GL_ARRAY_BUFFER, buf[0]); // vertices
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

		glBindBuffer(GL_ARRAY_BUFFER, buf[1]); // tex coords
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

		glUniform1i(uniloc[1], 0);
		
		glDrawArrays(GL_TRIANGLES, 0, num_vertices);
	}
};