#include <gtk/gtk.h>

int main(int argc, char **argv){
  GtkApplication *app;
  int stat;
  app = gtk_application_new("com.bustecz.ds", G_APPLICATION_FLAGS_NONE);
  stat = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);
  
  return stat;
}
