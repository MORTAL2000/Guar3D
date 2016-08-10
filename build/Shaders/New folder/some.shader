{
    "Description":
    "
        yet another shader.
        
    ",

    "Draw":
    "
        -- script.lua
        -- call some opengl funcs & example string arg funcs
        glClear(1);
        glClearColor(0.1,0.5,0.1,0.675);
        --setString('hello hello hello',123);
        --setString('This is the future');
        
    ",
    
    "Vertex":
    "
        attribute vec3 a_Pos;               
        uniform float _Time;                
        void main ()                        
        {                                   
            vec4 position = vec4(a_Pos,1.0);
            position.y += cos(_Time);       
            gl_Position = position;         
    
        }                                   
    
    ",
    
    "Fragment":
    "
        //precision mediump float;              
        uniform float _Time;                   
        void main()                            
        {                                      
        gl_FragColor = vec4(0.75,0.25,0.0, 1.0);
        }                                      
    
    "
    
}