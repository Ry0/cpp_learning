#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// #ifdef _WIN32
// #include <windows.h>
// #endif

/* GLヘッダーのリンク */
#include <OpenGL/gl.h>
#include <GLUT/glut.h>

/* GLUT用のコールバック関数 */
static void keyboard(unsigned char key, int x, int y);
static void resize(int w, int h);
static void display(void);
static void idle(void);

static void initState(void);

/* モデルの移動カウント */
static int count = 0;

int screenWidth = 320;
int screenHeight = 240;

/* 頂点データ */
float flatVertex[] = {
    /* Format: x, y, z */
	-30.0,  30.0,  0.0,	/* 0 */
     0.0,  -30.0,  0.0,	/* 1 */
     30.0,  30.0,  0.0,	/* 2 */
};
/* 頂点色 */
float flatColor[] = {
	1.0f, 0.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
};


/*
 * 三角形の描画
 */
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(screenWidth, screenHeight);
	glutCreateWindow(argv[0]);

	glutKeyboardFunc(keyboard);
	glutReshapeFunc(resize);
	glutDisplayFunc(display);
    glutIdleFunc(idle);

	/* GLステートの初期化 */
	initState();

	glutMainLoop();

	return 0;
}

/* ステート初期化 */
static void initState(void)
{
	glDisable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);
}


/* 描画のコールバック関数 */
void display(void)
{
	float rot;

	/* モデルビュー行列のセットアップ */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	/* 光源設定 */
	glDisable(GL_LIGHTING);

	/* 視点 */
	gluLookAt(0.0f, 0.0f, 120.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);

	/* 背景 */
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();

	rot = count * 1.0f;
	count++;
	glRotatef(rot, 0.0f, 1.0f, 0.0f);

	/* 頂点配列の設定 */
	/* 位置座標 */
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, flatVertex);

	/* 頂点色 */
	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(4, GL_FLOAT, 0, flatColor);

	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glPopMatrix();

	glFlush();

	glutSwapBuffers();
}

/* Windowリサイズのコールバック関数 */
static void resize(
	int width,		/* ウィンドウの幅 */
	int height		/* ウィンドウの高さ */
)
{
	/* ビューポートの設定 */
	glViewport(0, 0, width, height);

	/* 射影行列のセットアップ */
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();
	glFrustum(
		-0.8f * (1.0f),		/* left */
		 0.8f * (1.0f),		/* right */
		-0.8f * (0.75f),	/* bottom */
		 0.8f * (0.75f),	/* top */
		 1.0f, 10000.0f		/* near, far */
		);
}


static void idle(void)
{
	glutPostRedisplay();
}


static void keyboard(unsigned char key, int x, int y)
{
	if (key == 'q' || key == 'Q')
	{
		exit(0);
	}
}
