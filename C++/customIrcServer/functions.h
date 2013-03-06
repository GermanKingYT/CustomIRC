#ifndef FUNCTIONS_H
#define FUNCTIONS_H


enum logTags{
    LOGTAGS_IRC = 0x00,
    LOGTAGS_MAIN
};
extern const char* fromQstringToCharArray(QString str);
extern void doLog(const logTags tag, const char* msg, ...);
#endif // FUNCTIONS_H
