#include "MainState.hpp"

#include <iostream>
#include <Tank/Graphics/Image.hpp>
#include <Tank/Graphics/BitmapText.hpp>
#include <Tank/Graphics/Font.hpp>
#include <Tank/Graphics/Text.hpp>
#include <Tank/System/Keyboard.hpp>
#include <Tank/System/Mouse.hpp>
#include "Animated.hpp"

tank::Font MainState::font;

MainState::MainState()
    : State()
{
    using namespace tank;

    font.loadFromFile("res/font.ttf");

    makeEntity<Entity>()->makeGraphic<Image>("res/zoommap.png");

    makeEntity<Animated>(Vectorf {200,200});
    auto anim1 = makeEntity<Animated>(Vectorf {60,70});
    auto& animGfx = anim1->getGraphic();
    animGfx->setScale(4);
    animGfx->setOrigin(animGfx->getSize() / 2);
    auto hb = anim1->getHitbox();
    anim1->setHitbox({- hb.w * 2, - hb.h * 2, hb.w * 2, hb.h * 2});

    auto bmText = makeEntity<Entity>(Vectorf {300, 20})->makeGraphic<BitmapText>(Image("res/font.png"), Vectori {50, 50});
    bmText->setText("WHEEE!");
    bmText->setRotation(50);

    auto ttfText = makeEntity<Entity>(Vectorf {300, 20})->makeGraphic<Text>(font);
    ttfText->setText("WHEEE!");
    ttfText->setRotation(50);


    connect(Keyboard::KeyDown(Key::A), [this]
            {
                auto pos = camera().getPos();
                camera().setPos(pos + Vectorf{-2,  0});
            });
    connect(Keyboard::KeyDown(Key::D), [this]
            {
                auto pos = camera().getPos();
                camera().setPos(pos + Vectorf{ 2,  0});
            });
    connect(Keyboard::KeyDown(Key::W), [this]
            {
                auto pos = camera().getPos();
                camera().setPos(pos + Vectorf{ 0, -2});
            });
    connect(Keyboard::KeyDown(Key::S), [this]
            {
                auto pos = camera().getPos();
                camera().setPos(pos + Vectorf{ 0,  2});
            });
    connect(Keyboard::KeyDown(Key::Q), [this]
            {
                auto rot = camera().getRotation();
                camera().setRotation(rot - 2);
            });
    connect(Keyboard::KeyDown(Key::E), [this]
            {
                auto rot = camera().getRotation();
                camera().setRotation(rot + 2);
            });
    connect(Keyboard::KeyDown(Key::Add), [this]
            {
                auto zoom = camera().getZoom().x;
                camera().setZoom(zoom * 1.1f);
            });
    connect(Keyboard::KeyDown(Key::Subtract), [this]
            {
                auto zoom = camera().getZoom().x;
                camera().setZoom(zoom / 1.1f);
            });
    connect(Mouse::MouseMovement() and Mouse::ButtonDown(Mouse::Button::Right),
            [this]
            {
                auto dt = Mouse::delta();
                auto pos = camera().getPos();
                camera().setPos(pos - dt);
            });
    connect(Mouse::WheelUp(),
            [this]
            {
                auto z = camera().getZoom();
                camera().setZoom(z*1.5);
            });
    connect(Mouse::WheelDown(),
            [this]
            {
                auto z = camera().getZoom();
                camera().setZoom(z/1.5);
            });
}

void MainState::update()
{
    State::update();
}
