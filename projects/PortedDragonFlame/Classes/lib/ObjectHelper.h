//
//  ObjectHelper.h
//  PortedDragonFlame
//
//  Created by Yonghong Shi on 1/5/14.
//
//

#ifndef PortedDragonFlame_ObjectHelper_h
#define PortedDragonFlame_ObjectHelper_h

template<class T, typename ...Args>
T* create(Args&&... params) {
    T* t = new T();
    if (t && t->init(params...)) {
        t->autorelease();
        return t;
    }
    CC_SAFE_DELETE(t);
    return nullptr;
}

template<class T>
class scoped_obj {
public:
    scoped_obj(T* obj, bool retain=false) {
        if(retain) {
            obj->retain();
        }
        obj=obj;
    }
    ~scoped_obj() {
        obj->release();
    }
    T & operator*() const {
        return *(this->obj);
    }
    T * operator->() const {
        return this->obj;
    }
private:
    T* obj;
};

#endif
