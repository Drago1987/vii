#include <gtk/gtk.h>

class GTKApplication
{
public:
    GTKApplication(int status_,int argc_, char **argv_);
    ~GTKApplication();
    int init();
    static void print_hello (GtkWidget *widget, gpointer   data);
    static void activate (GtkApplication *app, gpointer user_data);
    void version();

private:
   int status;
   int argc;
   char **argv;
   GtkApplication *app;
};

