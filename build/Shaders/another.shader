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
        glClearColor(getIncrementer()*0.01,0.5,0.1,0.675);
        --setString(getIncrementer());
        --setString('hello hello hello',123);
        --setString('This is the future');
        
    ",
    
    "Vertex":
    "
        //VertIn
        attribute vec3 a_Pos;     
        attribute vec2 a_UV;    
        
        //FragIn
        varying vec2 v_UV;
        
        //Uniforms
        uniform float _Time;   
        uniform mat4 _MVP;
        
        void main ()                        
        {                                   
            vec4 position = vec4(a_Pos,1.0);
            
            position *= _MVP;
            
            
            //position.x += cos(_Time);       
            gl_Position = position;  
        
            v_UV = a_UV;
        
        }                                    
    
    ",
    
    "Fragment":
    "
        //FragIn
        varying vec2 v_UV;
    
        //Uniforms
        uniform float _Time;        
        uniform sampler2D _Texture;
        
        // Constants
        const float c_AlphaCutOff = 1.0;
        
        // operations forward decs
        vec4 calculateTexelColor(const vec4 aFrag);
        vec4 alphaCutOff(const vec4 aFrag);
        
        //************
        // Entry point
        //************
        void main()                            
        {                                      
            vec4 rvalue = vec4(0);
            {
                rvalue = calculateTexelColor(rvalue);
                rvalue = alphaCutOff(rvalue);
            
            }
    
            gl_FragColor = rvalue;
        
        }     

        //*******************************
        //Fragment operations definitions
        //*******************************
        vec4 calculateTexelColor(const vec4 aFrag)
        {
            vec4 rvalue = aFrag;
            {
                rvalue = texture2D(_Texture, v_UV);
                
            }
            
            return rvalue;      
            
        }

        vec4 alphaCutOff(const vec4 aFrag)
        {
            vec4 rvalue = aFrag;
            {
                if (rvalue[3] < c_AlphaCutOff)
                    discard;  
                            
            }
            
            return rvalue;
            
        }        
    
    "
    
}