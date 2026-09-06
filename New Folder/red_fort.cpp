// ============================================================
//  Red Fort — Independence Day Scene   (C++ / OpenGL / freeGLUT)
//  Lahori Gate front, matched to the classic photo:
//    - two red-domed corner pavilions (chhatris)
//    - central arcade + row of small white domes
//    - waving Tiranga (dead centre) with Ashoka Chakra
//    - Air Force flypast trailing saffron / white / green smoke
//    - green mound + low crenellated front wall
//
//  Build (Linux):
//     sudo apt install freeglut3-dev
//     g++ red_fort.cpp -o red_fort -lGL -lGLU -lglut
//     ./red_fort            (Esc or q to quit)
//
//  Made for Kanak — Jai Hind
// ============================================================

#include <GL/glut.h>
#include <cmath>
#include <cstdlib>
#include <string>
#include <initializer_list>

static const float W = 1000.0f, H = 680.0f;
static const float PI = 3.14159265f;
static float gTime = 0.0f;

struct Col { float r,g,b; };
static const Col SAFFRON = {1.00f, 0.60f, 0.20f};
static const Col WHITE   = {1.00f, 1.00f, 1.00f};
static const Col GREEN   = {0.07f, 0.53f, 0.03f};
static const Col NAVY    = {0.04f, 0.06f, 0.42f};
static const Col STONE   = {0.63f, 0.21f, 0.16f};   // red sandstone
static const Col STONE_D = {0.44f, 0.13f, 0.10f};   // shadow
static const Col STONE_L = {0.76f, 0.30f, 0.24f};   // highlight
static const Col DOME    = {0.55f, 0.16f, 0.13f};   // dome maroon-red
static const Col DOME_L  = {0.72f, 0.26f, 0.21f};
static const Col CREAM   = {0.93f, 0.88f, 0.77f};   // arcade / small domes
static const Col CREAM_D = {0.80f, 0.73f, 0.60f};

static void col(const Col& c, float a = 1.0f) { glColor4f(c.r, c.g, c.b, a); }

static void rect(float x, float y, float w, float h) {
    glBegin(GL_QUADS);
        glVertex2f(x, y); glVertex2f(x+w, y); glVertex2f(x+w, y+h); glVertex2f(x, y+h);
    glEnd();
}

// bulbous (onion-ish) dome, flat side down at baseY
static void bulbDome(float cx, float baseY, float rx, float ry, const Col& c, const Col& hi) {
    col(c);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, baseY);
        for (int i = 0; i <= 48; ++i) {
            float t = PI * (float)i / 48.0f;                 // 0..PI
            float x = cx + rx * std::cos(t);
            float y = baseY + ry * std::pow(std::sin(t), 0.72f);  // fuller top
            glVertex2f(x, y);
        }
    glEnd();
    // left-side sheen
    glEnable(GL_BLEND);
    col(hi, 0.45f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx - rx*0.25f, baseY + ry*0.25f);
        for (int i = 12; i <= 30; ++i) {
            float t = PI * (float)i / 48.0f;
            glVertex2f(cx + rx*0.7f*std::cos(t), baseY + ry*0.8f*std::pow(std::sin(t),0.72f));
        }
    glEnd();
    // finial: neck + ball + spike
    col(CREAM_D);
    rect(cx - 2.0f, baseY + ry, 4.0f, ry*0.18f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, baseY + ry + ry*0.18f);
        for (int i = 0; i <= 14; ++i) {
            float a = 2.0f*PI*(float)i/14.0f;
            glVertex2f(cx + rx*0.11f*std::cos(a), baseY + ry + ry*0.18f + rx*0.11f*std::sin(a));
        }
    glEnd();
    col(CREAM_D);
    rect(cx - 1.0f, baseY + ry + ry*0.18f, 2.0f, ry*0.22f);
}

// filled pointed (lancet) arch silhouette
static void pointedArch(float cx, float baseY, float w, float h, const Col& c) {
    col(c);
    float hw = w * 0.5f;
    glBegin(GL_POLYGON);
        glVertex2f(cx - hw, baseY);
        glVertex2f(cx - hw, baseY + h*0.55f);
        for (int i = 0; i <= 16; ++i) {                    // left curve to apex
            float t = (float)i / 16.0f;
            float x = cx - hw*(1.0f - t);
            float y = baseY + h*0.55f + (h*0.45f)*std::sin(t*PI*0.5f);
            glVertex2f(x, y);
        }
        for (int i = 0; i <= 16; ++i) {                    // apex down to right
            float t = (float)i / 16.0f;
            float x = cx + hw*t;
            float y = baseY + h - (h*0.45f)*(1.0f - std::cos(t*PI*0.5f));
            glVertex2f(x, y);
        }
        glVertex2f(cx + hw, baseY + h*0.55f);
        glVertex2f(cx + hw, baseY);
    glEnd();
}

// row of merlons (crenellations) with cream caps
static void merlons(float x0, float x1, float y, float mw, float gap) {
    for (float x = x0; x + mw <= x1; x += mw + gap) {
        col(STONE);
        glBegin(GL_POLYGON);
            glVertex2f(x, y); glVertex2f(x+mw, y);
            glVertex2f(x+mw*0.80f, y+13.0f); glVertex2f(x+mw*0.20f, y+13.0f);
        glEnd();
        col(CREAM);
        rect(x+mw*0.18f, y+13.0f, mw*0.64f, 3.0f);
    }
}

// ============================================================
//  SKY + FLYPAST
// ============================================================
static void drawSky() {
    glBegin(GL_QUADS);
        glColor3f(0.16f, 0.42f, 0.78f); glVertex2f(0, H);      glVertex2f(W, H);
        glColor3f(0.66f, 0.82f, 0.94f); glVertex2f(W, H*0.28f); glVertex2f(0, H*0.28f);
    glEnd();
}

static void smokeTrail(float jx, float jy, const Col& c) {
    glEnable(GL_BLEND);
    const int N = 90;
    for (int i = 0; i < N; ++i) {
        float t = (float)i, t2 = (float)(i+1);
        float x0 = jx - t*6.0f,  x1 = jx - t2*6.0f;
        float th = 2.6f + t*0.13f;
        float a0 = 0.5f*(1.0f - t/N), a1 = 0.5f*(1.0f - t2/N);
        float dy = std::sin(x0*0.03f + gTime)*3.0f;
        glBegin(GL_QUAD_STRIP);
            glColor4f(c.r,c.g,c.b,a0); glVertex2f(x0, jy+th+dy); glVertex2f(x0, jy-th+dy);
            glColor4f(c.r,c.g,c.b,a1); glVertex2f(x1, jy+th+dy); glVertex2f(x1, jy-th+dy);
        glEnd();
    }
}
static void jet(float jx, float jy) {
    col({0.18f,0.20f,0.24f});
    glBegin(GL_TRIANGLES);
        glVertex2f(jx+20, jy); glVertex2f(jx-11, jy+5); glVertex2f(jx-11, jy-5);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2f(jx-2, jy); glVertex2f(jx-15, jy+12); glVertex2f(jx-9, jy);
        glVertex2f(jx-2, jy); glVertex2f(jx-15, jy-12); glVertex2f(jx-9, jy);
    glEnd();
    col({0.85f,0.90f,1.0f});
    glBegin(GL_TRIANGLES);
        glVertex2f(jx+12, jy); glVertex2f(jx+3, jy+2); glVertex2f(jx+3, jy-2);
    glEnd();
}
static void drawFlypast() {
    float span = W + 700.0f;
    struct J { float off, y; Col c; } jets[3] = {
        {0.0f,   H*0.86f, SAFFRON}, {120.0f, H*0.92f, WHITE}, {240.0f, H*0.86f, GREEN}
    };
    for (auto& j : jets) {
        float x = std::fmod(gTime*130.0f + j.off, span) - 350.0f;
        smokeTrail(x, j.y, j.c);
        jet(x, j.y);
    }
}

// ============================================================
//  FORT
// ============================================================
static void cornerPavilion(float cx) {
    // tower body
    col(STONE);   rect(cx-70, 170, 140, 185);
    col(STONE_D); rect(cx-70, 170, 14, 185);          // left shade
    col(STONE_L); rect(cx+56, 170, 14, 185);          // right light
    // two tall blind arches on the face
    pointedArch(cx-34, 200, 46, 118, STONE_D);
    pointedArch(cx+34, 200, 46, 118, STONE_D);
    col(CREAM);
    pointedArch(cx-34, 206, 34, 104, CREAM); pointedArch(cx-34, 214, 24, 92, STONE_D);
    pointedArch(cx+34, 206, 34, 104, CREAM); pointedArch(cx+34, 214, 24, 92, STONE_D);
    // cornice + jharokha band
    col(STONE_L); rect(cx-74, 350, 148, 10);
    merlons(cx-70, cx+70, 360, 18, 8);

    // open pavilion (pillars + arches) under the dome
    float baseY = 378;
    col(STONE_D); rect(cx-58, baseY, 116, 44);         // recessed backdrop
    col(STONE);
    for (float px : {cx-58.0f, cx-24.0f, cx+10.0f, cx+44.0f}) rect(px, baseY, 12, 44);
    col(STONE_L); rect(cx-64, baseY+44, 128, 9);       // pavilion cornice
    col(DOME);    rect(cx-42, baseY+53, 84, 10);       // drum
    // big red dome
    bulbDome(cx, baseY+63, 50, 66, DOME, DOME_L);
}

static void centralBlock() {
    // block (set slightly lower, drawn before towers)
    col(STONE);   rect(365, 185, 270, 150);
    col(STONE_D); rect(365, 185, 14, 150);
    col(STONE_L); rect(621, 185, 14, 150);
    // arcade of 5 cream pointed arches
    for (int i = 0; i < 5; ++i) {
        float cx = 400 + i*50.0f;
        pointedArch(cx, 205, 42, 108, STONE_D);
        pointedArch(cx, 210, 32, 98,  CREAM);
        pointedArch(cx, 216, 22, 86,  STONE_D);
    }
    // cornice
    col(STONE_L); rect(360, 335, 280, 9);
    // row of 7 small white domes
    for (int i = 0; i < 7; ++i) {
        float cx = 383 + i*39.0f;
        col(CREAM_D); rect(cx-13, 344, 26, 7);         // drum
        bulbDome(cx, 351, 15, 20, CREAM, WHITE);
    }
}

static void drawFort() {
    centralBlock();          // behind
    cornerPavilion(285.0f);  // left tower in front
    cornerPavilion(715.0f);  // right tower in front
}

// ============================================================
//  TIRANGA (waving mesh) + Ashoka Chakra  — dead centre
// ============================================================
static const float MAST_X  = 500.0f;
static const float FLAG_TOP = 500.0f;
static const float FLAG_W  = 150.0f;
static const float FLAG_H  = 92.0f;

static void meshPos(float u, float v, float& ox, float& oy) {
    float bx = MAST_X + u*FLAG_W;
    float by = FLAG_TOP - v*FLAG_H;
    float wave  = std::sin(6.2831f*u*1.5f - gTime*3.0f)*10.0f*u;
    wave       += std::sin(6.2831f*u*2.5f - gTime*4.6f)*4.0f*u;
    ox = bx; oy = by + wave;
}
static Col stripe(float v) {
    if (v < 1.0f/3.0f) return SAFFRON;
    if (v < 2.0f/3.0f) return WHITE;
    return GREEN;
}
static void chakra() {
    col(NAVY); glLineWidth(2.0f);
    float rv = 0.135f, ru = rv*(FLAG_H/FLAG_W), cx, cy;
    glBegin(GL_LINE_LOOP);
        for (int i=0;i<48;++i){ float a=2*PI*i/48; meshPos(0.5f+ru*std::cos(a),0.5f+rv*std::sin(a),cx,cy); glVertex2f(cx,cy); }
    glEnd();
    float hx,hy; meshPos(0.5f,0.5f,hx,hy);
    glLineWidth(1.3f);
    glBegin(GL_LINES);
        for (int i=0;i<24;++i){ float a=2*PI*i/24; meshPos(0.5f+ru*std::cos(a),0.5f+rv*std::sin(a),cx,cy); glVertex2f(hx,hy); glVertex2f(cx,cy); }
    glEnd();
}
static void drawFlag() {
    col(STONE_L); rect(MAST_X-3, 340, 6, FLAG_TOP-340+8);
    col(WHITE);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(MAST_X, FLAG_TOP+9);
        for (int i=0;i<=16;++i){ float a=2*PI*i/16; glVertex2f(MAST_X+5*std::cos(a), FLAG_TOP+9+5*std::sin(a)); }
    glEnd();
    const int NU=28, NV=16;
    for (int i=0;i<NU;++i){
        float u0=(float)i/NU, u1=(float)(i+1)/NU;
        glBegin(GL_QUAD_STRIP);
        for (int j=0;j<=NV;++j){
            float v=(float)j/NV; Col c=stripe(v);
            float sh=0.86f+0.14f*std::sin(6.2831f*u0*1.5f-gTime*3.0f);
            float x,y; col({c.r*sh,c.g*sh,c.b*sh});
            meshPos(u0,v,x,y); glVertex2f(x,y);
            meshPos(u1,v,x,y); glVertex2f(x,y);
        }
        glEnd();
    }
    chakra();
}

// ============================================================
//  FRONT GROUND: green mound + low crenellated wall
// ============================================================
static void drawFrontGround() {
    glBegin(GL_QUADS);
        glColor3f(0.09f,0.34f,0.11f); glVertex2f(0,0);   glVertex2f(W,0);
        glColor3f(0.24f,0.55f,0.22f); glVertex2f(W,178); glVertex2f(0,178);
    glEnd();
    // low front rampart wall
    col(STONE);   rect(90, 96, 820, 46);
    col(STONE_D); rect(90, 96, 820, 10);
    col(STONE_L); rect(90, 138, 820, 5);
    merlons(96, 904, 142, 22, 12);
}

// ============================================================
//  TEXT
// ============================================================
static void text(float x, float y, const std::string& s, void* f, const Col& c) {
    col(c); glRasterPos2f(x,y);
    for (char ch : s) glutBitmapCharacter(f, ch);
}
static float tw(const std::string& s, void* f){ float w=0; for(char ch:s) w+=glutBitmapWidth(f,ch); return w; }
static void drawText() {
    std::string a="HAPPY INDEPENDENCE DAY";
    std::string b="15 AUGUST  -  80 YEARS OF FREEDOM  -  JAI HIND";
    void* f1=GLUT_BITMAP_TIMES_ROMAN_24; void* f2=GLUT_BITMAP_HELVETICA_18;
    text((W-tw(a,f1))*0.5f, 58, a, f1, WHITE);
    text((W-tw(b,f2))*0.5f, 32, b, f2, SAFFRON);
}

// ============================================================
//  GLUT
// ============================================================
static void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_BLEND); glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    drawSky();
    drawFlypast();
    drawFort();
    drawFlag();
    drawFrontGround();
    drawText();
    glutSwapBuffers();
}
static void reshape(int w,int h){
    glViewport(0,0,w,h); glMatrixMode(GL_PROJECTION); glLoadIdentity();
    glOrtho(0,W,0,H,-1,1); glMatrixMode(GL_MODELVIEW); glLoadIdentity();
}
static void timer(int){ gTime+=0.016f; glutPostRedisplay(); glutTimerFunc(16,timer,0); }
static void keyboard(unsigned char k,int,int){ if(k==27||k=='q') std::exit(0); }

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize((int)W,(int)H);
    glutCreateWindow("Red Fort - Independence Day  |  Jai Hind");
    glShadeModel(GL_SMOOTH);
    glClearColor(0.16f,0.42f,0.78f,1.0f);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0,timer,0);
    glutMainLoop();
    return 0;
}
