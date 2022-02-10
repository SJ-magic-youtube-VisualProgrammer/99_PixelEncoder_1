/************************************************************
ビルトイン関数(一部)
	http://qiita.com/edo_m18/items/71f6064f3355be7e4f45
	
GLSLで宣言時に配列を初期化する
	https://qiita.com/aa_debdeb/items/49f8706143b4e9e231c1
************************************************************/
#version 120
#extension GL_ARB_texture_rectangle : enable
#extension GL_EXT_gpu_shader4 : enable

/************************************************************
************************************************************/
#define ID 4

/************************************************************
************************************************************/
bool is_equal(float val_0, float val_1);
int sj_division(float x, float y);
int sj_mod(float x, float y);

/************************************************************
************************************************************/
uniform sampler2DRect texture_0;

uniform int NumDots = 7;
uniform int xN = 1;
uniform int id = 0;

/************************************************************
************************************************************/

/******************************
******************************/
void main(){
#if (ID == 0)
	vec4 color = vec4(1.0, 0.0, 0.0, 1.0);
	
	gl_FragColor = color * gl_Color;
	return;
	
#elif(ID == 1)
	vec2 Coord = gl_TexCoord[0].xy;
	
	vec4 color;
	// if(Coord.y == 1){
	// if( is_equal(Coord.y, 1.5) ){
	if(floor(Coord.y) == 1.0){
		color = vec4(1.0, 0.0, 0.0, 1.0);
	}else{
		color = vec4(0.0, 0.0, 0.0, 1.0);
	}
	
	gl_FragColor = color * gl_Color;
	return;
	
#elif(ID == 2)
	vec4 color;
	float x = 7; // int x = 7;
	float y = 7; // int y = 7;
	
	// if(x/y == 1.0f){
	if(sj_division(x, y) == 1){
		color = vec4(1.0, 0.0, 0.0, 1.0);
	}else{
		color = vec4(0.0, 1.0, 0.0, 1.0);
	}
	
	gl_FragColor = color * gl_Color;
	return;
	
#elif(ID == 3)
	vec4 color;
	float x = 7; // int x = 7;
	float y = 7; // int y = 7;
	
	// if(mod(x, y) == 0){
	if(sj_mod(x, y) == 0){
		color = vec4(1.0, 0.0, 0.0, 1.0);
	}else{
		color = vec4(0.0, 1.0, 0.0, 1.0);
	}
	
	gl_FragColor = color * gl_Color;
	return;
	
#elif(ID == 4)
	vec2 Coord = gl_TexCoord[0].xy;
	
	int _y = sj_division( sj_mod(floor(Coord.y), NumDots * xN), xN );
	int _x = sj_division( sj_mod(floor(Coord.x), NumDots * xN), xN );
	
	int id_ofThisPix = _y * NumDots + _x;
	
	vec4 color;
	if( id_ofThisPix == id){
		color = vec4(1.0, 0.0, 0.0, 1.0);
	}else{
		color = vec4(0.0, 0.0, 0.0, 1.0);
	}
	
	gl_FragColor = color * gl_Color;
	return;
#endif
}

/******************************
******************************/
bool is_equal(float val_0, float val_1){
	return (abs(val_0 - val_1) < 1e-3) ? true : false;
	// return (abs(val_0 - val_1) < 1e-8) ? true : false;
}

/******************************
******************************/
int sj_division(float x, float y){
	float delta = 1e-3;
	// float delta = 1e-7;
	
	// return int ((x + delta) / y);
	return int (x/y + delta);
}

/******************************
******************************/
int sj_mod(float x, float y){
	float delta = 1e-3;
	// float delta = 1e-7;
	
	// return int( mod(x + delta, y) );
	return int(x - y * floor(x/y + delta));
}

