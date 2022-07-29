# OpenGL入門
* サイト
    * GLUTによる「手抜き」OpenGL入門
        * https://tokoik.github.io/opengl/libglut.html
    * Ubuntu 18.04 LTSにGLUTをインストール
        * https://qiita.com/willow-micro/items/db8b13e7d34e5349237b
    * OpenGL入門
        * http://wisdom.sakura.ne.jp/system/opengl/

# OpenGLざっくり説明
* 【C++/OpenGL】NO.1 OpenGLの仕組みと三角形表示
    * https://shizenkarasuzon.hatenablog.com/entry/2020/05/21/020650

# OpenGL 3D
* 【OpenGL第3回】3D描画(ビューポート・視点位置・透視投影の設定)
    * http://tecsingularity.com/opengl/viewport/

# 作成する図形 glBeginの引数
* glBegin(GL_LINE_LOOP)
    * 線状の図形の作成
* glBegin(GL_POLYGON)
    * 塗りつぶし図形の作成

# マウス操作による視点移動
* OpenGLを使った3次元描画
    * https://qiita.com/sekishoku/items/9ce6f79cfcc0cc6266d1

* gluLookAtの説明
    * gluLookAt(2.0, 2.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    * 視点位置（x, y, z）、注視点（x, y, z）、姿勢(どっちが上か)（x, y, z）
