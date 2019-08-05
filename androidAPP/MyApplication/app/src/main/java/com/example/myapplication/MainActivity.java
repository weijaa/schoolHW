package com.example.myapplication;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.webkit.WebSettings;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    private TextView t;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        t = findViewById(R.id.textView);
    }
    int size=30;
    public void big(View v){
        t.setTextSize(++size);
    }
    public void small(View v){
        t.setTextSize(--size);
    }
    public void send(View v){
        TextView ed = findViewById(R.id.editText);
        t.setText("hello"+ed.getText().toString());
    }
}
