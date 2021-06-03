package cn.edu.xust.iot.model.entity;

public class Power {
    private Integer id;

    private String powerRule;

    private String powerName;

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getPowerRule() {
        return powerRule;
    }

    public void setPowerRule(String powerRule) {
        this.powerRule = powerRule == null ? null : powerRule.trim();
    }

    public String getPowerName() {
        return powerName;
    }

    public void setPowerName(String powerName) {
        this.powerName = powerName == null ? null : powerName.trim();
    }
}