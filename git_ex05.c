#include <gtk/gtk.h>

static void btn_clicked1 (GtkButton *btn, gpointer user_data){
  g_print("Button 1 clicked.\n");
}

static void btn_clicked2 (GtkButton *btn, gpointer user_data){
  GtkWindow *win = GTK_WINDOW(user_data);
  gtk_window_destroy(win);
}

static void app_activate (GApplication *app, gpointer user_data){
  GtkWidget *win;
  GtkWidget *box;
  GtkWidget *lbl;
  GtkWidget *btn1;
  GtkWidget *btn2;

  win = gtk_application_window_new(GTK_APPLICATION(app));
  gtk_window_set_title(GTK_WINDOW(win), "GtkBox");
  gtk_window_set_default_size(GTK_WINDOW(win), 400,200);

  box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
  gtk_box_set_homogeneous(GTK_BOX(box), TRUE);
  gtk_window_set_child(GTK_WINDOW(win), box);

  lbl = gtk_label_new("CFromZero");

  btn1 = gtk_button_new_with_label("Button 1");
  g_signal_connect(btn1, "clicked", G_CALLBACK(btn_clicked1), NULL);

  btn2 = gtk_button_new_with_label("Button 2 (Quit)");
  g_signal_connect(btn2, "clicked", G_CALLBACK(btn_clicked2), win);
  
  gtk_box_append(GTK_BOX(box), lbl);
  gtk_box_append(GTK_BOX(box), btn1);
  gtk_box_append(GTK_BOX(box), btn2);

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
