// #include "Extension\DirectX11\DXGraphics11.hpp"
#include "StdAfx.h"
#include "GameMain.h"
#include <fstream>

#include <fstream>

/// <summary>
/// Allows the game to perform any initialization it needs to before starting to run.
/// This is where it can query for any required services and load all of your content.
/// Initialize will enumerate through any components and initialize them as well.
/// </summary>
bool GameMain::Initialize()
{
	// TODO: Add your initialization logic here
	WindowTitle(_T("ES Game Library"));

	Player = GraphicsDevice.CreateSpriteFromFile(_T("chara1.png"));

	player_x = 0;
	player_y = 0;


	return true;
}

/// <summary>
/// Finalize will be called once per game and is the place to release
/// all resource.
/// </summary>
void GameMain::Finalize()
{
	// TODO: Add your finalization logic here

}

/// <summary>
/// Allows the game to run logic such as updating the world,
/// checking for collisions, gathering input, and playing audio.
/// </summary>
/// <returns>
/// Scene continued value.
/// </returns>
int GameMain::Update()
{
	KeyboardBuffer key_buffer = Keyboard->GetBuffer();

	KeyboardState key = Keyboard->GetState();

	// TODO: Add your update logic here

	if (key.IsKeyDown(Keys_Up)) {

		player_y -= 5;

	}

	if (key.IsKeyDown(Keys_Down)) {

		player_y += 5;

	}


	if (key.IsKeyDown(Keys_Right)) {


		player_x += 5;
	}


	if (key.IsKeyDown(Keys_Left)) {

		player_x -= 5;

	}

	

	if (key_buffer.IsPressed(Keys_Space)) {
		return GAME_SCENE(new ResultScene);
	}

	return 0;
}

/// <summary>
/// This is called when the game should draw itself.
/// </summary>
void GameMain::Draw()
{
	// TODO: Add your drawing code here
	GraphicsDevice.Clear(Color_CornflowerBlue);

	GraphicsDevice.BeginScene();


	SpriteBatch.Begin();
	SpriteBatch.Draw(*Player, Vector3(player_x, player_y, 0));

	SpriteBatch.End();

	GraphicsDevice.EndScene();
}
