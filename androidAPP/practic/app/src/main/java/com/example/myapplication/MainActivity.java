package com.example.myapplication;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    protected TextView word;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        word = findViewById(R.id.textView);
    }
    int size = 30;
    public void bigger(View v){
        word.setTextSize(++size);
    }
    public void smaller(View v){
        word.setTextSize(--size);
    }
    public  void wd(View v){
        TextView pick = findViewById(R.id.editText);
        word.setText("hello" + pick.getText().toString());
    }
}
