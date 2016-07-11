
#import <stdio.h>

void stackf_();

void stackc() {
    printf(" C: in 'stackc'\n");
    stackf_();
}

void stackc_() {
    printf(" C: in 'stackc_'\n");
    stackf_();
