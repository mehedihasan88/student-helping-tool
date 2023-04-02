#ifndef CLASS_NOTE_H
#define CLASS_NOTE_H


class class_note
{
private:
    char note_line[10000];
    char subject_name[100];
    char file_name[1000];
    char read_char;
public:
    class_note();
    void create();
    void show_today();
    void find();

};

#endif // CLASS_NOTE_H

