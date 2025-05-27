#include "RotatorFactoryInitializer.h"

// Khởi tạo registry khi chương trình bắt đầu
RotatorFactoryInitializer::RotatorFactoryInitializer() {
    auto& registry = RotatorFactoryRegistry::getInstance();
        
    registry.registerRotator("I", []() { 
        return std::make_unique<IRotator>(); 
    });
        
    registry.registerRotator("J", []() { 
        return std::make_unique<CounterclockwiseRotator>(); 
    });
        
    registry.registerRotator("L", []() { 
        return std::make_unique<CounterclockwiseRotator>(); 
    });
        
    registry.registerRotator("S", []() { 
        return std::make_unique<StandardRotator>(); 
    });
        
    registry.registerRotator("T", []() { 
        return std::make_unique<StandardRotator>();
    });
        
    registry.registerRotator("Z", []() { 
        return std::make_unique<StandardRotator>(); 
    });
        
    // O không cần rotator (nullptr)
    registry.registerRotator("O", []() { 
        return nullptr; 
    });
}
