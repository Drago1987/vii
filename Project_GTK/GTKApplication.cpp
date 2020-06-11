#include "GTKApplication.hpp"
#include <iostream>



GTKApplication::GTKApplication(int status_,int argc_, char **argv_):
       status(status_),
       argc(argc_),
       argv(argv_)
{
    app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
}

GTKApplication::~GTKApplication()
{
    g_object_unref (app);
}

int GTKApplication::init(){
    return status;
}

void GTKApplication::version(){
    std::cout << 
    "GTK_MAJOR_VERSION " <<
    GTK_MAJOR_VERSION << "\n" <<
    "GTK_MINOR_VERSION " <<
    GTK_MINOR_VERSION << "\n" <<
    "GTK_MICRO_VERSION " <<
    GTK_MICRO_VERSION << "\n" <<
    "GTK_BINARY_AGE " <<
    GTK_BINARY_AGE << "\n" <<
    "GTK_INTERFACE_AGE " <<
    GTK_INTERFACE_AGE << "\n";
}

void GTKApplication::print_hello (GtkWidget *widget, gpointer   data)
{
  g_print ("Hello World\n");
}

void GTKApplication::activate (GtkApplication *app, gpointer user_data)
{
  GtkWidget *window;
  GtkWidget *window2;
  GtkWidget *button;
  GtkWidget *button2;
  GtkWidget *button_box;
  GtkWidget *button_box2;

  window = gtk_application_window_new (app);
  window2 = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Window");
  gtk_window_set_title (GTK_WINDOW (window2), "Window2");
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);
  gtk_window_set_default_size (GTK_WINDOW (window2), 200, 200);

  button_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
  gtk_container_add (GTK_CONTAINER (window), button_box);

  button_box2 = gtk_button_box_new (GTK_ORIENTATION_VERTICAL);
  gtk_container_add (GTK_CONTAINER (window2), button_box2);

  button = gtk_button_new_with_label ("Close");
  button2 = gtk_button_new_with_label ("Test");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
  g_signal_connect (button2, "clicked", G_CALLBACK (print_hello), NULL);
  g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);
//   g_signal_connect_swapped (button2, "clicked", G_CALLBACK (gtk_widget_destroy), window2);
  gtk_container_add (GTK_CONTAINER (button_box), button);
  gtk_container_add (GTK_CONTAINER (button_box2), button2);

  gtk_widget_show_all (window);
  gtk_widget_show_all (window2);
}

