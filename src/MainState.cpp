#include "MainState.hpp"

#include <iostream>
#include <Tank/Graphics/Image.hpp>
#include <Tank/Graphics/BitmapText.hpp>
#include <Tank/Graphics/Font.hpp>
#include <Tank/Graphics/Text.hpp>
#include <Tank/System/Keyboard.hpp>
#include <Tank/System/Mouse.hpp>
#include "Animated.hpp"

tank::Font MainWorld::font;

MainWorld::MainWorld()
    : World()
{
    using namespace tank;

    font.loadFromFile("res/font.ttf");

    // makeEntity returns an observing_ptr, meaning you can chain access
    // makeGraphic<typename T> - T defaults to tank::Image
    makeEntity<Entity>()->makeGraphic("res/zoommap.png");

    // Animated is a derived class of Entity within this project
    makeEntity<Animated>(Vectorf {200,200});

    observing_ptr<Entity> anim1 = makeEntity<Animated>(Vectorf {60,70});
    std::unique_ptr<Graphic> const& animGfx = anim1->getGraphic();
    Rectu hb = anim1->getHitbox();

    // Set the scale of anim1 to 4 and resize its hitbox accordingly
    animGfx->setScale(4);
    animGfx->setOrigin(animGfx->getSize() / 2);
    anim1->setHitbox({- hb.w * 2, - hb.h * 2, hb.w * 2, hb.h * 2});

    // Two different forms of text
    auto bmText = makeEntity<Entity>(Vectorf {300, 20})->makeGraphic<BitmapText>(Image("res/font.png"), Vectori {50, 50});
    bmText->setText("WHEEE!");
    bmText->setRotation(50);

    auto ttfText = makeEntity<Entity>(Vectorf {300, 20})->makeGraphic<Text>(font);
    ttfText->setText("WHEEE!");
    ttfText->setRotation(50);


    // Camera movement with wasd keys
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
    // Camera rotation with qe keys
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
    // Camera zoom with +- keys
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
    // Camera movement with rclick + drag
    connect(Mouse::MouseMovement() and Mouse::ButtonDown(Mouse::Button::Right),
            [this]
            {
                auto const& dx = Mouse::delta();
                auto const& zoom = camera().getZoom();
                auto pos = camera().getPos();

                pos.x -= dx.x / zoom.x;
                pos.y -= dx.y / zoom.y;

                camera().setPos(pos);
            });
    // Camera zoom with mousewheel
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
