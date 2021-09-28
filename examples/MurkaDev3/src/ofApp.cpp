#include "ofApp.h"

namespace murka {
	class CircleField : public View_NEW<CircleField> {
	public:

		bool isPointInsideRect(MurkaPoint p, vector<MurkaPoint> rectPoints) {
			int cnt = 0;
			for (int i = 0; i < 4; i++) {
				if (isLinesIntersect(p, p + MurkaPoint(10000, 0), rectPoints[i], rectPoints[(i + 1) % 4]) == 1) {
					cnt++;
				}
			}
			return cnt % 2 != 0;
		}
			 
		bool isLinesIntersect(MurkaPoint v11, MurkaPoint v12, MurkaPoint v21, MurkaPoint v22) {
			float d1, d2;
			float a1, a2, b1, b2, c1, c2;

			a1 = v12.y - v11.y;
			b1 = v11.x - v12.x;
			c1 = (v12.x * v11.y) - (v11.x * v12.y);

			d1 = (a1 * v21.x) + (b1 * v21.y) + c1;
			d2 = (a1 * v22.x) + (b1 * v22.y) + c1;

			if (d1 > 0 && d2 > 0) return 0;
			if (d1 < 0 && d2 < 0) return 0;

			a2 = v22.y - v21.y;
			b2 = v21.x - v22.x;
			c2 = (v22.x * v21.y) - (v21.x * v22.y);

			d1 = (a2 * v11.x) + (b2 * v11.y) + c2;
			d2 = (a2 * v12.x) + (b2 * v12.y) + c2;

			if (d1 > 0 && d2 > 0) return 0;
			if (d1 < 0 && d2 < 0) return 0;

			if ((a1 * b2) - (a2 * b1) == 0.0f) return 0;// 2;

			return 1;
		}

		MurkaPoint getPointOnCircle(float deg) {
			float x = (shape.size.x / 2) + (shape.size.x / 2 - 20) * sinf(deg * PI / 180);
			float y = (shape.size.x / 2) + (shape.size.x / 2 - 20) * cosf(deg * PI / 180);
			return MurkaPoint(x, y);
		}

		void internalDraw(const MurkaContextBase & c) {

			bool inside = c.isHovered() * !areChildrenHovered(c);

			if (isHovered != inside) {
				isHovered = inside;
				onHoverChangeCallback(*this);
			}


		
			//        if (c.mouseButtonsChanged[0] && c.mouseDown[0])

			if (c.mouseDownPressed[0]) {
				onClickCallback(*this);
				onClickCallbackPosition(*this, { 25, 11 });
			}

			c.pointerToRenderer->setColor(100);
			c.pointerToRenderer->drawRectangle(0, 0, shape.size.x, shape.size.y);

			c.pointerToRenderer->setColor(255);
			vector<MurkaPoint> vert;
			for (int i = 0; i <= 360; i += 5) {
				vert.push_back(getPointOnCircle(i));
			}
			c.pointerToRenderer->setLineWidth(3);
			for (int i = 0; i < vert.size()-1; i ++) {
				c.pointerToRenderer->drawLine(vert[i].x, vert[i].y, vert[i + 1].x, vert[i + 1].y);
			}
			c.pointerToRenderer->setLineWidth(1);

			

			vector<MurkaPoint> rectPoints;
			rectPoints.push_back(MurkaPoint(-50, -10));
			rectPoints.push_back(MurkaPoint(-50, 10));
			rectPoints.push_back(MurkaPoint(50, 10));
			rectPoints.push_back(MurkaPoint(50, -10));

			float angle1 = 30;// c.mousePosition.x;
			MurkaPoint p = getPointOnCircle(angle1);
			MurkaPoint p2 = getPointOnCircle(angle1 + 0.01);

			ofMatrix4x4 m;
			m.rotate(atan2f((p2 - p).y, (p2 - p).x) * 180 / PI, 0, 0, 1);
			m.translate(p.x, p.y, 0);
			for (int i = 0; i < 4; i++) {
				ofVec3f v = ofVec3f(rectPoints[i].x, rectPoints[i].y, 0) * m;
				rectPoints[i] = MurkaPoint(v.x, v.y);
			}
			for (int i = 0; i < 4; i++) {
				//c.pointerToRenderer->drawLine(rectPoints[i].x, rectPoints[i].y, rectPoints[(i + 1) % 4].x, rectPoints[(i + 1) % 4].y);
			}
			 
			if (isPointInsideRect(c.mousePosition, rectPoints)) {
				c.pointerToRenderer->setColor(255, 0, 0);
			}
			else 
				c.pointerToRenderer->setColor(255);

			c.pointerToRenderer->pushMatrix();
			c.pointerToRenderer->disableFill();
			c.pointerToRenderer->translate(p.x, p.y, 0);

			c.pointerToRenderer->rotateZRad(atan2f((p2 - p).y, (p2 - p).x));

			c.pointerToRenderer->drawRectangle(-50, -10, 100, 20);
			c.pointerToRenderer->enableFill();
			c.pointerToRenderer->popMatrix();
			 
		};

		

		bool isHovered = false;


		MURKA_CALLBACK(CircleField, // class name
			onHoverChangeCallback, // callback variable name
			onHoverChange
		) // callback setter

			MURKA_CALLBACK(CircleField,
				onClickCallback,
				onClick
			)

			MURKA_CALLBACK_1ARGUMENT(CircleField, // class name
				onClickCallbackPosition, // callback variable name
				onClickPosition, // callback setter
				MurkaPoint
			) // callback argument type

			MURKA_PARAMETER(CircleField, // class name
				TextAlignment, // parameter type
				alignment, // parameter variable name
				getAlignment, // getter
				withAlignment, // setter
				TEXT_LEFT
			) // default

			MURKA_PARAMETER(CircleField, // class name
				std::string, // parameter type
				label, // parameter variable name
				getLabel, // getter
				text, // setter
				""
			) // default



		// MURKA_SUPPORT_DIRECT_DRAW(Label)
		virtual bool wantsClicks() override { return false; } // override this if you want to signal that you don't want clicks
	};
}



//---- ----------------------------------------------------------
void ofApp::setup() {

	// Murka setup
	m.setRenderer(ofGetGLRenderer().get());
	m.setWindow(ofGetWindowPtr());
	m.setResourcesPath(ofToDataPath(""));

	//
	m.shape = { 0, 0, ofGetWidth(), ofGetHeight() };
	m.setScreenScale(screenScale);


}

//--------------------------------------------------------------
void ofApp::createChildren() {

}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {

	animationRestart();

	ofClear(200);


	auto time = ofGetElapsedTimef();


	// Initial drawing and setup & object-oriented mode

	m.setFont("Roboto-Regular.ttf", 12);



	m.begin();

	m.setColor(220, A(hoveredLabel) * 220, A(hoveredLabel) * 220);
	//    ofSetColor(220, A(hoveredLabel) * 220, A(hoveredLabel) * 220);

		/*
		drawWidget_NEW<Label>(m, { 50, 50, 300, 50 })
			.text("time passed: " + std::to_string(ofGetElapsedTimef()) + " ; hovered ? " + (hoveredLabel ? " yes " : " no "))
			.onHoverChange([&](Label& l) {
				hoveredLabel = l.isHovered;
			})
			.onClick([&](Label& l) {
				ofLog() << "clicked!";
			});
		*/

		// 1. Унаследовать контекст от рендерера? Чтобы вызывать рендеринг из виджетов не обращаясь к указателю на рендер.  Вердикт: не вйыдет. Передавать указатель на рендер в internalDraw.
	//      + вынести Renderer из наследников объекта Murka в отдельный объект, чтобы рисование внутри виджетов и в самой программе было устроено одинаково.
		// 2. Добавить такую же функцию draw контексту? Зачем?
		// 3. Решить с цветом. 255 или 1? 1.
		// 4. resetKeyboardFocus когда вьюшка пропала.

		// И ещё:
		// 5. Параметры у коллбэков внутри виджетов?

	m.draw<Label>({ 0, 0, 300, 50 })
		.text("time passed: " + std::to_string(ofGetElapsedTimef()) + " ; hovered ? " + (hoveredLabel ? " yes " : " no "))
		.onHoverChange([&](Label& l) {
			hoveredLabel = l.isHovered;
		})
		.onClick([&](Label& l) {
			ofLog() << "clicked!";
		})
		.onClickPosition([&](Label &l, MurkaPoint p) {
			ofLog() << "clicked! callback arguments: " << p.x << " ; " << p.y;
		});
	m.currentContext.commitDeferredView();

	m.draw<CircleField>({ 50, 50, 400, 400 })
		.text("time passed: " + std::to_string(ofGetElapsedTimef()) + " ; hovered ? " + (hoveredLabel ? " yes " : " no "))
		.onHoverChange([&](CircleField& l) {
			hoveredLabel = l.isHovered;
		})
		.onClick([&](CircleField& l) {
			ofLog() << "clicked!";
		})
		.onClickPosition([&](CircleField &l, MurkaPoint p) {
			ofLog() << "clicked! callback arguments: " << p.x << " ; " << p.y;
		});
	m.currentContext.commitDeferredView();







	//    drawWidget_NEW<ReticleGrid>(m, { 50, 50, 200, 50 })
	//        .setBackgroundColor(200, 0, 200)
	//        .controlYPR(&ypr);


	auto ffont = m.getCurrentFont();

	// Commit deferred view calls the base class draw() instead of derived one. Fix this somehow.


	/*
	Label::purr(m, { 50, 50, 200, 50 })
		.label = "yo";

	Label().draw3(m, { 50, 50, 200, 50 });
//    commit();
	 */


	m.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
