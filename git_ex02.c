#include <gtk/gtk.h>

static void app_activate (GApplication *app, gpointer user_data){
  GtkWidget *win;
  win = gtk_window_new();
  gtk_window_set_application (GTK_WINDOW(win), GTK_APPLICATION(app));
  gtk_widget_show(win);
}

int main(int argc, char **argv){
  GtkApplication *app;
  int stat;
  
  app = gtk_application_new("com.example.www", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK(app_activate), NULL);
  stat = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_ref(app);
  
  return stat;
}
