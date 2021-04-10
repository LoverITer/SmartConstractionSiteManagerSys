package cn.edu.xust.iot.camera.builder;

import cn.edu.xust.iot.camera.CommandManagerImpl;

/**
 * @author HuangXin
 * @since 2021/4/9 8:37
 */
public class DefaultCommandBuilder implements CommandBuilder {

    StringBuilder buidler=null;
    String command=null;

    public DefaultCommandBuilder() {
        create();
    }


    public DefaultCommandBuilder(String rootpath) {
        create(rootpath);
    }


    @Override
    public CommandBuilder create(String rootpath) {
        buidler=new StringBuilder(rootpath);
        return this;
    }

    @Override
    public CommandBuilder create() {
        return create(CommandManagerImpl.config.getPath());
    }

    @Override
    public CommandBuilder add(String key, String val) {
        return add(key).add(val);
    }

    @Override
    public CommandBuilder add(String val) {
        if(buidler!=null) {
            buidler.append(val);
            addBlankspace();
        }
        return this;
    }

    @Override
    public CommandBuilder build() {
        if(buidler!=null) {
            command=buidler.toString();
        }
        return this;
    }

    private void addBlankspace() {
        buidler.append(" ");
    }

    @Override
    public String get() {
        if(command==null) {
            build();
        }
        return command;
    }
    
}
