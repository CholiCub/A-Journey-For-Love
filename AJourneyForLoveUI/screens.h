#ifndef SCREENS_H
#define SCREENS_H

enum GameScreen { UNKNOWN = -1, STUDIO_LOGO = 0, TITLE, PLAYER_SETTINGS, GAMEPLAY, ENDING };
GameScreen currentScreen;

//Studio Logo Screen
void InitStudioLogoScreen();
void UpdateStudioLogoScreen();
void DrawStudioLogoScreen();
void UnloadStudioLogoScreen();
int FinsihStudioLogoScreen();
//Title Screen
void InitTitleScreen();
void UpdateTitleScreen();
void DrawTitleScreen();
void UnloadTitleScreen();
int FinsihTitleScreen();
//Player Settings Screen
void InitPlayerSettingsScreen();
void UpdatePlayerSettingsScreen();
void DrawPlayerSettingsScreen();
void UnloadPlayerSettingsScreen();
int FinsihPlayerSettingsScreen();
//Gameplay Screen
void InitGameplayScreen();
void UpdateGameplayScreen();
void DrawGameplayScreen();
void UnloadGameplayScreen();
int FinsihGameplayScreen();
//Ending Screen
void InitEndingScreen();
void UpdateEndingScreen();
void DrawEndingScreen();
void UnloadEndingScreen();
int FinsihEndingScreen();

#endif