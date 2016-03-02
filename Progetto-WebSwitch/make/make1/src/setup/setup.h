#ifndef SETUP_H
#define SETUP_H

void *gestorenumeroprocessifiglidisponibili(void *arg);
void sighandler(int segnale);
struct infoserver * setup(int listens);

#endif
