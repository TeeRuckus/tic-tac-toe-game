/*******************************************************************************
 * file: userinterface.c                                                       *
 * author: tawana david kwaramba                                               *
 * student id: 19476700                                                        *
 * date created: 30/09/19                                                      *
 * date last modified:                                                         *
 * purpose of file: this is where all the interfaces meet in one location to   *
 *                  make the programme. i.e. this file exposes the user to     *
 *                  the functionallity of the programme.                       *
 *******************************************************************************/
#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H
    void userInterface(int *gameSettings);
    Boolean validateInput(int input);
    void displayCurrentSettings(int *inGameSettings);
    Boolean validateUserSettings(int mSetting, int nSetting, int kSetting);
    void changeGameSettings(int *inGameSettings);
    void checkFileWriteSucceed(Status result);
#endif
