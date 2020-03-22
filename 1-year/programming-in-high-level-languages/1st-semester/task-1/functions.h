#pragma once

bool checkScanfResult(int result, int countVars);

bool checkDate(int day, int month, int year);

bool checkTime(int hour, int min, int sec);

std::string checkInputData(int day, int month, int year, int hour, int min, int sec, int result, int countVars);